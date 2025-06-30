/********************************************************************************
** Form generated from reading UI file 'schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_H
#define UI_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Schedule
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *AddBtn;
    QPushButton *ClrBtn;

    void setupUi(QDialog *Schedule)
    {
        if (Schedule->objectName().isEmpty())
            Schedule->setObjectName("Schedule");
        Schedule->resize(539, 357);
        verticalLayout = new QVBoxLayout(Schedule);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(Schedule);
        listWidget->setObjectName("listWidget");
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        verticalLayout->addWidget(listWidget);

        AddBtn = new QPushButton(Schedule);
        AddBtn->setObjectName("AddBtn");

        verticalLayout->addWidget(AddBtn);

        ClrBtn = new QPushButton(Schedule);
        ClrBtn->setObjectName("ClrBtn");

        verticalLayout->addWidget(ClrBtn);


        retranslateUi(Schedule);

        QMetaObject::connectSlotsByName(Schedule);
    } // setupUi

    void retranslateUi(QDialog *Schedule)
    {
        Schedule->setWindowTitle(QCoreApplication::translate("Schedule", "\345\244\207\345\277\230\345\275\225", nullptr));
        AddBtn->setText(QCoreApplication::translate("Schedule", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
        ClrBtn->setText(QCoreApplication::translate("Schedule", "\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Schedule: public Ui_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H
