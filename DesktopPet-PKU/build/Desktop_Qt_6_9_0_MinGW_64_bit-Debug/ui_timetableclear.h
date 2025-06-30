/********************************************************************************
** Form generated from reading UI file 'timetableclear.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLECLEAR_H
#define UI_TIMETABLECLEAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TimetableClear
{
public:
    QLineEdit *lineEdit;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *TimetableClear)
    {
        if (TimetableClear->objectName().isEmpty())
            TimetableClear->setObjectName("TimetableClear");
        TimetableClear->resize(300, 200);
        lineEdit = new QLineEdit(TimetableClear);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 40, 140, 20));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirm = new QPushButton(TimetableClear);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(40, 120, 75, 30));
        cancel = new QPushButton(TimetableClear);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(180, 120, 75, 30));

        retranslateUi(TimetableClear);
        QObject::connect(confirm, &QPushButton::clicked, TimetableClear, qOverload<>(&QDialog::accept));
        QObject::connect(cancel, &QPushButton::clicked, TimetableClear, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TimetableClear);
    } // setupUi

    void retranslateUi(QDialog *TimetableClear)
    {
        TimetableClear->setWindowTitle(QCoreApplication::translate("TimetableClear", "\346\270\205\347\251\272", nullptr));
        lineEdit->setText(QCoreApplication::translate("TimetableClear", "\347\241\256\345\256\232\350\246\201\346\270\205\347\251\272\344\275\240\347\232\204\350\257\276\347\250\213\350\241\250\345\220\227", nullptr));
        confirm->setText(QCoreApplication::translate("TimetableClear", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("TimetableClear", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimetableClear: public Ui_TimetableClear {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLECLEAR_H
