#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QList>
#include <QPair>
#include "backend/deepseekservice.h"
#include <QAction>
#include <QRect>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_sendButton_clicked();
    void onApiResponse(const QString &reply);
    void onApiError(const QString &error);
    void on_settingsButton_clicked();
private:
    void addMessage(const QString &sender, const QString &message, bool isUser = true, bool isReplacement = false);
    QAction *m_settingsAction;
    QRect m_settingsIconRect; // 用于存储图标的绘制区域
    bool m_isHoveringSettingsIcon = false; // 标记鼠标是否悬停在图标上

    Ui::ChatDialog *ui;
    DeepSeekService *deepseekService;
    QList<QPair<QString, QString>> messageHistory; // <role, content>
};

#endif // CHATDIALOG_H
