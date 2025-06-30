/********************************************************************************
** Form generated from reading UI file 'timetableremind.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLEREMIND_H
#define UI_TIMETABLEREMIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TimetableRemind
{
public:
    QPushButton *confirm;
    QPushButton *cancel;
    QLineEdit *lineEdit;

    void setupUi(QDialog *TimetableRemind)
    {
        if (TimetableRemind->objectName().isEmpty())
            TimetableRemind->setObjectName("TimetableRemind");
        TimetableRemind->resize(300, 200);
        confirm = new QPushButton(TimetableRemind);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(40, 120, 75, 30));
        cancel = new QPushButton(TimetableRemind);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(180, 120, 75, 30));
        lineEdit = new QLineEdit(TimetableRemind);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(60, 40, 180, 20));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(TimetableRemind);
        QObject::connect(confirm, &QPushButton::clicked, TimetableRemind, qOverload<>(&QDialog::accept));
        QObject::connect(cancel, &QPushButton::clicked, TimetableRemind, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TimetableRemind);
    } // setupUi

    void retranslateUi(QDialog *TimetableRemind)
    {
        TimetableRemind->setWindowTitle(QCoreApplication::translate("TimetableRemind", "Dialog", nullptr));
        confirm->setText(QCoreApplication::translate("TimetableRemind", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("TimetableRemind", "\345\217\226\346\266\210", nullptr));
        lineEdit->setText(QCoreApplication::translate("TimetableRemind", "\344\275\240\347\232\204\346\224\271\345\212\250\350\277\230\346\234\252\344\277\235\345\255\230\357\274\214\347\241\256\345\256\232\345\205\263\351\227\255\345\220\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimetableRemind: public Ui_TimetableRemind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLEREMIND_H
