/********************************************************************************
** Form generated from reading UI file 'timetableclose.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLECLOSE_H
#define UI_TIMETABLECLOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TimetableClose
{
public:
    QPushButton *confirm;
    QPushButton *cancel;
    QLineEdit *lineEdit;

    void setupUi(QDialog *TimetableClose)
    {
        if (TimetableClose->objectName().isEmpty())
            TimetableClose->setObjectName("TimetableClose");
        TimetableClose->resize(300, 200);
        confirm = new QPushButton(TimetableClose);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(40, 120, 75, 30));
        cancel = new QPushButton(TimetableClose);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(180, 120, 75, 30));
        lineEdit = new QLineEdit(TimetableClose);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 40, 140, 20));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(TimetableClose);
        QObject::connect(confirm, &QPushButton::clicked, TimetableClose, qOverload<>(&QDialog::accept));
        QObject::connect(cancel, &QPushButton::clicked, TimetableClose, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TimetableClose);
    } // setupUi

    void retranslateUi(QDialog *TimetableClose)
    {
        TimetableClose->setWindowTitle(QCoreApplication::translate("TimetableClose", "\345\205\263\351\227\255", nullptr));
        confirm->setText(QCoreApplication::translate("TimetableClose", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("TimetableClose", "\345\217\226\346\266\210", nullptr));
        lineEdit->setText(QCoreApplication::translate("TimetableClose", "\347\241\256\345\256\232\350\246\201\345\205\263\351\227\255\344\275\240\347\232\204\350\257\276\347\250\213\350\241\250\345\220\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimetableClose: public Ui_TimetableClose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLECLOSE_H
