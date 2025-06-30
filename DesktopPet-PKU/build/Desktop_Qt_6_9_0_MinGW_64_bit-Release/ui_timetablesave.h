/********************************************************************************
** Form generated from reading UI file 'timetablesave.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLESAVE_H
#define UI_TIMETABLESAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TimetableSave
{
public:
    QLineEdit *lineEdit;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *TimetableSave)
    {
        if (TimetableSave->objectName().isEmpty())
            TimetableSave->setObjectName("TimetableSave");
        TimetableSave->resize(300, 200);
        lineEdit = new QLineEdit(TimetableSave);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 40, 140, 20));
        lineEdit->setCursorPosition(10);
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirm = new QPushButton(TimetableSave);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(40, 120, 75, 30));
        cancel = new QPushButton(TimetableSave);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(180, 120, 75, 30));

        retranslateUi(TimetableSave);
        QObject::connect(confirm, &QPushButton::clicked, TimetableSave, qOverload<>(&QDialog::accept));
        QObject::connect(cancel, &QPushButton::clicked, TimetableSave, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TimetableSave);
    } // setupUi

    void retranslateUi(QDialog *TimetableSave)
    {
        TimetableSave->setWindowTitle(QCoreApplication::translate("TimetableSave", "\344\277\235\345\255\230", nullptr));
        lineEdit->setText(QCoreApplication::translate("TimetableSave", "\347\241\256\345\256\232\350\246\201\344\277\235\345\255\230\344\275\240\347\232\204\344\277\256\346\224\271\345\220\227", nullptr));
        confirm->setText(QCoreApplication::translate("TimetableSave", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("TimetableSave", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimetableSave: public Ui_TimetableSave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLESAVE_H
