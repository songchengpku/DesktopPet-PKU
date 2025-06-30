/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QTextBrowser *chatBrowser;
    QTextEdit *inputBox;
    QPushButton *sendButton;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName("ChatDialog");
        ChatDialog->resize(453, 435);
        chatBrowser = new QTextBrowser(ChatDialog);
        chatBrowser->setObjectName("chatBrowser");
        chatBrowser->setGeometry(QRect(11, 11, 256, 192));
        inputBox = new QTextEdit(ChatDialog);
        inputBox->setObjectName("inputBox");
        inputBox->setGeometry(QRect(13, 223, 256, 192));
        sendButton = new QPushButton(ChatDialog);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(276, 305, 93, 28));

        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QCoreApplication::translate("ChatDialog", "Dialog", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatDialog", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
