/********************************************************************************
** Form generated from reading UI file 'sports.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPORTS_H
#define UI_SPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sports
{
public:
    QPushButton *btnRecord;
    QPushButton *btnStats;
    QProgressBar *progressDistance;
    QProgressBar *progressCount;

    void setupUi(QDialog *Sports)
    {
        if (Sports->objectName().isEmpty())
            Sports->setObjectName("Sports");
        Sports->resize(749, 516);
        btnRecord = new QPushButton(Sports);
        btnRecord->setObjectName("btnRecord");
        btnRecord->setGeometry(QRect(132, 301, 93, 28));
        btnStats = new QPushButton(Sports);
        btnStats->setObjectName("btnStats");
        btnStats->setGeometry(QRect(478, 301, 93, 28));
        progressDistance = new QProgressBar(Sports);
        progressDistance->setObjectName("progressDistance");
        progressDistance->setGeometry(QRect(12, 22, 120, 27));
        progressDistance->setValue(24);
        progressCount = new QProgressBar(Sports);
        progressCount->setObjectName("progressCount");
        progressCount->setGeometry(QRect(12, 56, 120, 27));
        progressCount->setValue(24);

        retranslateUi(Sports);

        QMetaObject::connectSlotsByName(Sports);
    } // setupUi

    void retranslateUi(QDialog *Sports)
    {
        Sports->setWindowTitle(QCoreApplication::translate("Sports", "\350\277\220\345\212\250\347\256\241\347\220\206", nullptr));
        btnRecord->setText(QCoreApplication::translate("Sports", "\350\256\260\345\275\225", nullptr));
        btnStats->setText(QCoreApplication::translate("Sports", "\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sports: public Ui_Sports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPORTS_H
