/********************************************************************************
** Form generated from reading UI file 'timetable_delete.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLE_DELETE_H
#define UI_TIMETABLE_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Timetable_delete
{
public:
    QPushButton *complete;

    void setupUi(QDialog *Timetable_delete)
    {
        if (Timetable_delete->objectName().isEmpty())
            Timetable_delete->setObjectName("Timetable_delete");
        Timetable_delete->resize(300, 600);
        complete = new QPushButton(Timetable_delete);
        complete->setObjectName("complete");
        complete->setGeometry(QRect(220, 520, 48, 48));

        retranslateUi(Timetable_delete);

        QMetaObject::connectSlotsByName(Timetable_delete);
    } // setupUi

    void retranslateUi(QDialog *Timetable_delete)
    {
        Timetable_delete->setWindowTitle(QCoreApplication::translate("Timetable_delete", "\345\210\240\351\231\244\350\257\276\347\250\213", nullptr));
        complete->setText(QCoreApplication::translate("Timetable_delete", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Timetable_delete: public Ui_Timetable_delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLE_DELETE_H
