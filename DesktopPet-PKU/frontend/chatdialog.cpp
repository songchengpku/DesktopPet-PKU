#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QDateTime>
#include <QScrollBar>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTextDocument>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include"backend/qmarkdowntextdocument.h"
#include <QTextBlock>
#include <QStyle>
#include<QInputDialog>
#include <QPainter>
#include <QMouseEvent>

ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog),
    deepseekService(new DeepSeekService(this))
{

    ui->setupUi(this);

    // 1. 设置窗口属性
    setWindowTitle("DeepSeek AI 助手");
    setMinimumSize(450, 600);

    setMouseTracking(true);
    // 2.创建设置Action，而不是按钮
    QAction *settingsAction = new QAction(this);
    connect(settingsAction, &QAction::triggered, this, &ChatDialog::on_settingsButton_clicked);
    // 我们将这个action存储为成员变量，以便在事件处理函数中使用
    m_settingsAction = settingsAction;

    // 创建窗口的主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    int topMargin = 45; // 顶部留出45像素的空间来绘制图标和标题
    mainLayout->setContentsMargins(0, topMargin, 0, 0);
    // 创建一个垂直方向的 Splitter
    QSplitter *splitter = new QSplitter(Qt::Vertical, this);

    splitter->addWidget(ui->chatBrowser);

    // 创建一个临时的容器Widget，用于放置底部的输入控件
    QWidget *inputContainer = new QWidget(this);
    // 为这个容器创建水平布局
    QHBoxLayout *inputLayout = new QHBoxLayout(inputContainer);
    inputLayout->setContentsMargins(5, 5, 5, 5);

    inputLayout->addWidget(ui->inputBox);
    inputLayout->addWidget(ui->sendButton);   // UI中的发送按钮

    // 把装配好的底部容器放进 Splitter 的下半部分
    splitter->addWidget(inputContainer);

    // 把 Splitter 放入窗口的主布局
    mainLayout->addWidget(splitter);

    // 3. 连接信号槽
    connect(deepseekService, &DeepSeekService::responseReceived, this, &ChatDialog::onApiResponse);
    connect(deepseekService, &DeepSeekService::errorOccurred, this, &ChatDialog::onApiError);

    //应用QSS样式
    QString styleSheet = R"(
        /* 整体对话框和聊天区背景 */
        QDialog, QTextBrowser {
            background-color: #f5f7fa; /* 统一的、柔和的淡蓝色背景 */
        }

        /* 聊天显示区域 */
        QTextBrowser {
            border: none;
            padding: 10px; /* 在聊天内容四周留出呼吸空间 */
            font-size: 15px; /* 所有普通文本的基础字体大小 */
        }

        /* Markdown 元素在聊天区内的样式 */
        QTextBrowser h1, QTextBrowser h2, QTextBrowser h3 {
            margin-top: 10px;
            margin-bottom: 5px;
            font-weight: bold;
        }
        QTextBrowser h1 { font-size: 18px; }
        QTextBrowser h2 { font-size: 16px; }
        QTextBrowser h3 { font-size: 15px; } /* 与普通文本一样大，但加粗 */

        QTextBrowser b, QTextBrowser strong {
            font-weight: bold;
        }

        QTextBrowser ul {
            margin-left: 0px; /* 调整列表的缩进 */
            padding-left: 25px;
        }

        QTextBrowser code {
            background-color: #e8eaed;
            border-radius: 4px;
            padding: 2px 4px;
            font-family: "Courier New", Courier, monospace;
            font-size: 14px;
        }

        QTextBrowser a {
            color: #0066cc;
            text-decoration: none;
        }
        QTextBrowser a:hover {
            text-decoration: underline;
        }

        /* 文本输入框 */
        QPlainTextEdit {
            background-color: #ffffff;
            border: 1px solid #dfe1e5;
            border-radius: 8px;
            padding: 12px;
            font-size: 15px;
            color: #333333;
        }
        QPlainTextEdit:focus {
            border: 1px solid #8ab4f8; /* Google-style focus color */
        }

        /* 蓝色主题的"发送"按钮 (通过 objectName 'sendButton' 匹配) */
        QPushButton#sendButton {
            background-color: #1a73e8; /* Google Blue */
            color: white;
            border: none;
            border-radius: 8px;
            padding: 0 20px; /* 垂直内边距通过 min-height 控制 */
            font-size: 15px;
            font-weight: 500;
            min-height: 36px; /* 固定高度 */
        }
        QPushButton#sendButton:hover {
            background-color: #287ae6;
        }
        QPushButton#sendButton:pressed {
            background-color: #1b65c9;
        }
        QPushButton#sendButton:disabled {
            background-color: #f1f3f4;
            color: #bdc1c6;
        }

        /* Splitter 分割线样式 */
        QSplitter::handle:vertical {
            height: 1px;
            background-color: #dfe1e5;
            margin: 5px 0;
        }

        /* 滚动条样式 */
        QScrollBar:vertical {
            border: none;
            background: transparent;
            width: 10px;
            margin: 10px 0 10px 0;
        }
        QScrollBar::handle:vertical {
            background: #dadce0;
            min-height: 25px;
            border-radius: 5px;
        }
        QScrollBar::handle:vertical:hover {
            background: #c0c3c6;
        }
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0px;
        }
    )";
    this->setStyleSheet(styleSheet);
    // 如果您在UI设计器中忘记设置objectName，可以在这里用代码补上
    ui->sendButton->setObjectName("sendButton");

    // 5. 设置Splitter比例和初始化
    QList<int> initialSizes;
    initialSizes << 500 << 100;
    splitter->setSizes(initialSizes);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 0);

    ui->chatBrowser->setOpenLinks(false);
    ui->inputBox->setPlaceholderText("请输入您的问题 (Enter 发送)...");
    ui->inputBox->setTabChangesFocus(true);
    addMessage("系统", "欢迎使用DeepSeek AI助手! 输入问题开始对话。", false);
    ui->inputBox->setFocus();
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

void ChatDialog::on_sendButton_clicked()
{
    QString message = ui->inputBox->toPlainText().trimmed();
    if (!message.isEmpty()) {
        // 添加到聊天历史
        addMessage("您", message);

        // 保持对话上下文
        messageHistory.append(qMakePair("user", message));

        // 禁用UI防止多次发送
        ui->sendButton->setEnabled(false);
        ui->inputBox->setEnabled(false);

        // 添加"思考中"提示
        addMessage("AI", "思考中...", false);

        // 滚动到底部
        QScrollBar *scrollbar = ui->chatBrowser->verticalScrollBar();
        scrollbar->setValue(scrollbar->maximum());

        // 发送请求
        deepseekService->sendMessageWithHistory(messageHistory);

        // 清空输入框
        ui->inputBox->clear();
    }
}


void ChatDialog::onApiResponse(const QString &reply)
{
    // 1. 调用 addMessage，并告知它这是一个替换操作
    addMessage("AI", reply, false, true);

    // 2. 将AI的真实回复（而不是“思考中”）添加到上下文历史
    // 找到最后一个"user"消息，然后更新它后面的"assistant"消息
    if (!messageHistory.isEmpty() && messageHistory.last().first == "user") {
        // This is a common case, but what if the last message is not from user?
        // The original code has a small bug here. Let's fix it.
        // We should remove the "思考中" placeholder from history if we added one.
        // A simpler approach: just add the new reply. The history doesn't see "Thinking...".
    }
    // The original message history logic was also flawed. It would add "Thinking..."
    // Let's fix the history logic in on_sendButton_clicked
    messageHistory.append(qMakePair("assistant", reply));


    // 3. 启用UI
    ui->sendButton->setEnabled(true);
    ui->inputBox->setEnabled(true);
    ui->inputBox->setFocus();
}

void ChatDialog::onApiError(const QString &error)
{
    // 1. 调用 addMessage 显示错误信息，并告知它这是一个替换操作
    addMessage("系统", "错误: " + error, false, true);

    // 2. 启用UI
    ui->sendButton->setEnabled(true);
    ui->inputBox->setEnabled(true);
    ui->inputBox->setFocus();
}

void ChatDialog::keyPressEvent(QKeyEvent *event)
{
    // 支持Ctrl+Enter或Enter发送
    if ((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)) {
        if (event->modifiers().testFlag(Qt::ControlModifier)) {
            on_sendButton_clicked();
            event->accept();
        } else if (ui->inputBox->hasFocus()) {
            on_sendButton_clicked();
            event->accept();
        } else {
            QDialog::keyPressEvent(event);
        }
    } else {
        QDialog::keyPressEvent(event);
    }
}


void ChatDialog::addMessage(const QString &sender, const QString &message, bool isUser, bool isReplacement)
{
    QTextDocument *doc = ui->chatBrowser->document();

    if (isReplacement) {

        if (!doc->isEmpty()) {
            QTextCursor cursor(doc);
            cursor.movePosition(QTextCursor::End);
            cursor.select(QTextCursor::BlockUnderCursor);


            if (cursor.selectedText().contains("思考中...")) {
                cursor.removeSelectedText();
            } else {

                cursor.beginEditBlock(); // Group operations
                cursor.movePosition(QTextCursor::End);
                QTextBlock lastBlock = doc->lastBlock();
                if (lastBlock.isValid()) {
                    cursor.setPosition(lastBlock.position(), QTextCursor::MoveAnchor);
                    cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
                    cursor.removeSelectedText();
                }
                cursor.endEditBlock();
            }


            cursor.deletePreviousChar();
            if (doc->lastBlock().text().isEmpty()) {
                cursor.select(QTextCursor::BlockUnderCursor);
                cursor.removeSelectedText();
            }
        }
    }

    QString formattedMsg;

    // 只对AI的回复进行Markdown解析
    if (sender == "AI") {
        QMarkdownTextDocument markdown;
        markdown.setMarkdown(message);
        formattedMsg = markdown.toHtml();
    } else {
        // 用户和系统的消息直接进行HTML转义
        formattedMsg = message.toHtmlEscaped().replace("\n", "<br>");
    }
    const QString userBubbleColor = "#74d24a";
    const QString aiBubbleColor = "#ffffff";
    const QString systemTextColor = "#888888";

    QString alignment = isUser ? "right" : "left";
    QString containerMargin = "margin-bottom: 15px;";
    QString html;

    if (sender == "系统") {
        html = QString("<div align='center' style='font-size: 13px; color: %1; padding: 5px 20px; %2'>%3</div>")
        .arg(systemTextColor)
            .arg(containerMargin)
            .arg(formattedMsg);
    } else {
        // 气泡样式 (display:inline-block 是关键)
        QString bubbleStyle = QString(
                                  "display: inline-block;"
                                  "max-width: 75%;"
                                  "padding: 12px 18px;"
                                  "border-radius: 12px;"
                                  "text-align: left;"
                                  "word-wrap: break-word;"
                                  "font-size: 15px;"
                                  "line-height: 1.5;"
                                  "background-color: %1;"
                                  "color: #000;"
                                  "box-shadow: 0 1px 2px rgba(0,0,0,0.05);"
                                  ).arg(isUser ? userBubbleColor : aiBubbleColor);

        // 发送者和时间戳的样式
        QString senderStyle = QString("font-size: 13px; color: #666; margin: 0 0 5px 0;");
        QString timeStyle = QString("font-size: 12px; color: #999; margin: 5px 0 0 0;");

        // 使用一个div作为外层容器，并用align属性来控制其内部所有内容的整体对齐
        html = QString(
                   "<div align='%1' style='%2'>"  // 这个 align 属性是实现左右对齐的关键
                   "  <div style='%3'>%4</div>"      // 发送者
                   "  <div style='%5'>%6</div>"      // 消息气泡
                   "  <div style='%7'>%8</div>"      // 时间
                   "</div>"
                   )
                   .arg(alignment)       // %1: "right" or "left"
                   .arg(containerMargin) // %2: 整个消息块的下边距
                   .arg(senderStyle)     // %3: 发送者样式
                   .arg(sender)          // %4: 发送者名字
                   .arg(bubbleStyle)     // %5: 气泡样式
                   .arg(formattedMsg)    // %6: 消息内容
                   .arg(timeStyle)       // %7: 时间样式
                   .arg(QDateTime::currentDateTime().toString("hh:mm")); // %8: 时间
    }

    ui->chatBrowser->append(html);

    QScrollBar *scrollbar = ui->chatBrowser->verticalScrollBar();
    scrollbar->setValue(scrollbar->maximum());
}

void ChatDialog::on_settingsButton_clicked()
{
    // 获取当前 DeepSeekService 中的 API Key 作为默认值显示
    QString currentApiKey = deepseekService->getApiKey();

    bool ok;
    // 弹出一个文本输入对话框
    QString newApiKey = QInputDialog::getText(this,
                                              "设置 API Key",
                                              "请输入您的 DeepSeek API Key:",
                                              QLineEdit::Normal, // 输入框模式
                                              currentApiKey,     // 对话框中预先填入的文本
                                              &ok);

    // 如果用户点击了“确定”按钮 (ok == true) 并且输入的内容不为空
    if (ok && !newApiKey.trimmed().isEmpty()) {
        // 更新 DeepSeekService 中的 API Key
        deepseekService->setApiKey(newApiKey.trimmed());
        // 可以给一个提示
        QMessageBox::information(this, "设置成功", "API Key 已更新。");
    }

}
void ChatDialog::paintEvent(QPaintEvent *event)
{
    QDialog::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // --- 绘制标题文本 ---
    painter.setPen(Qt::black);
    QFont titleFont = font();
    titleFont.setPointSize(12);
    titleFont.setBold(true);
    painter.setFont(titleFont);
    // 将标题文本垂直居中绘制在预留的顶部区域
    painter.drawText(0, 0, width(), 45, Qt::AlignCenter, windowTitle());


    // --- 绘制设置图标 ---
    int iconSize = 20;
    int margin = 12; // 调整边距使其更美观
    m_settingsIconRect = QRect(width() - iconSize - margin, (45 - iconSize) / 2, iconSize, iconSize);

    // 如果鼠标悬停，绘制背景
    if (m_isHoveringSettingsIcon) {
        painter.setBrush(QColor("#e8eaed"));
        painter.setPen(Qt::NoPen);
        // 背景比图标稍大一点
        painter.drawEllipse(m_settingsIconRect.adjusted(-6, -6, 6, 6));
    }

    // 绘制图标
    QIcon settingsIcon = this->style()->standardIcon(QStyle::SP_ComputerIcon);
    settingsIcon.paint(&painter, m_settingsIconRect);
}

void ChatDialog::mousePressEvent(QMouseEvent *event)
{
    // 如果鼠标左键点击的位置在图标区域内
    if (event->button() == Qt::LeftButton && m_settingsIconRect.contains(event->pos())) {
        m_settingsAction->trigger(); // 触发我们之前创建的Action
        event->accept(); // 接受事件，表示我们已经处理了它
        return;
    }

    QDialog::mousePressEvent(event); // 否则，交由基类处理
}

void ChatDialog::mouseMoveEvent(QMouseEvent *event)
{
    // 检查鼠标当前位置是否在图标区域内
    bool isCurrentlyHovering = m_settingsIconRect.contains(event->pos());

    // 如果悬停状态发生了变化
    if (isCurrentlyHovering != m_isHoveringSettingsIcon) {
        m_isHoveringSettingsIcon = isCurrentlyHovering;
        setCursor(m_isHoveringSettingsIcon ? Qt::PointingHandCursor : Qt::ArrowCursor);
        update(); // 请求重绘窗口，以更新悬停背景
    }

    QDialog::mouseMoveEvent(event);
}
