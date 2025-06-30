/********************************************************************************
** Form generated from reading UI file 'stats.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_H
#define UI_STATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_stats
{
public:

    void setupUi(QDialog *stats)
    {
        if (stats->objectName().isEmpty())
            stats->setObjectName("stats");
        stats->resize(400, 300);

        retranslateUi(stats);

        QMetaObject::connectSlotsByName(stats);
    } // setupUi

    void retranslateUi(QDialog *stats)
    {
        stats->setWindowTitle(QCoreApplication::translate("stats", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stats: public Ui_stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
