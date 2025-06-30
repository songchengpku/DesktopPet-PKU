/********************************************************************************
** Form generated from reading UI file 'mainwindowclose.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWCLOSE_H
#define UI_MAINWINDOWCLOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mainwindowclose
{
public:
    QPushButton *confirm;
    QPushButton *cancel;
    QLineEdit *lineEdit;

    void setupUi(QDialog *mainwindowclose)
    {
        if (mainwindowclose->objectName().isEmpty())
            mainwindowclose->setObjectName("mainwindowclose");
        mainwindowclose->resize(300, 200);
        confirm = new QPushButton(mainwindowclose);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(40, 120, 75, 24));
        cancel = new QPushButton(mainwindowclose);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(180, 120, 75, 24));
        lineEdit = new QLineEdit(mainwindowclose);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 40, 140, 20));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(mainwindowclose);
        QObject::connect(confirm, &QPushButton::clicked, mainwindowclose, qOverload<>(&QDialog::accept));
        QObject::connect(cancel, &QPushButton::clicked, mainwindowclose, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(mainwindowclose);
    } // setupUi

    void retranslateUi(QDialog *mainwindowclose)
    {
        mainwindowclose->setWindowTitle(QCoreApplication::translate("mainwindowclose", "\345\205\263\351\227\255\346\241\214\351\235\242\345\256\240\347\211\251", nullptr));
        confirm->setText(QCoreApplication::translate("mainwindowclose", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("mainwindowclose", "\345\217\226\346\266\210", nullptr));
        lineEdit->setText(QCoreApplication::translate("mainwindowclose", "\347\241\256\345\256\232\345\205\263\351\227\255\346\241\214\351\235\242\345\256\240\347\211\251\345\220\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowclose: public Ui_mainwindowclose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWCLOSE_H
