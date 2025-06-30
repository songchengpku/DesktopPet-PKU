/********************************************************************************
** Form generated from reading UI file 'timetable.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLE_H
#define UI_TIMETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Timetable
{
public:
    QPushButton *add;
    QPushButton *dlt;
    QTableWidget *tableWidget;
    QPushButton *save;
    QPushButton *close;
    QPushButton *clear;

    void setupUi(QDialog *Timetable)
    {
        if (Timetable->objectName().isEmpty())
            Timetable->setObjectName("Timetable");
        Timetable->resize(900, 600);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        Timetable->setFont(font);
        add = new QPushButton(Timetable);
        add->setObjectName("add");
        add->setGeometry(QRect(400, 450, 48, 48));
        dlt = new QPushButton(Timetable);
        dlt->setObjectName("dlt");
        dlt->setGeometry(QRect(490, 450, 48, 48));
        tableWidget = new QTableWidget(Timetable);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QFont font1;
        font1.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font2);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem19);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(40, 40, 775, 386));
        tableWidget->setMinimumSize(QSize(758, 0));
        tableWidget->setMaximumSize(QSize(16777215, 386));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font3.setPointSize(9);
        font3.setBold(true);
        tableWidget->setFont(font3);
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ArrowCursor)));
        tableWidget->setMouseTracking(false);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        save = new QPushButton(Timetable);
        save->setObjectName("save");
        save->setGeometry(QRect(820, 40, 48, 48));
        close = new QPushButton(Timetable);
        close->setObjectName("close");
        close->setGeometry(QRect(820, 220, 48, 48));
        clear = new QPushButton(Timetable);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(820, 130, 48, 48));

        retranslateUi(Timetable);

        QMetaObject::connectSlotsByName(Timetable);
    } // setupUi

    void retranslateUi(QDialog *Timetable)
    {
        Timetable->setWindowTitle(QCoreApplication::translate("Timetable", "\350\257\276\347\250\213\350\241\250", nullptr));
        add->setText(QCoreApplication::translate("Timetable", "\346\267\273\345\212\240", nullptr));
        dlt->setText(QCoreApplication::translate("Timetable", "\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Timetable", "\346\230\237\346\234\237\344\270\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Timetable", "\346\230\237\346\234\237\344\272\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Timetable", "\346\230\237\346\234\237\344\270\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Timetable", "\346\230\237\346\234\237\345\233\233", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Timetable", "\346\230\237\346\234\237\344\272\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Timetable", "\346\230\237\346\234\237\345\205\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Timetable", "\346\230\237\346\234\237\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Timetable", "\347\254\254\344\270\200\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Timetable", "\347\254\254\344\272\214\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Timetable", "\347\254\254\344\270\211\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Timetable", "\347\254\254\345\233\233\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Timetable", "\347\254\254\344\272\224\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Timetable", "\347\254\254\345\205\255\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Timetable", "\347\254\254\344\270\203\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Timetable", "\347\254\254\345\205\253\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Timetable", "\347\254\254\344\271\235\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Timetable", "\347\254\254\345\215\201\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Timetable", "\347\254\254\345\215\201\344\270\200\350\212\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Timetable", "\347\254\254\345\215\201\344\272\214\350\212\202", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        save->setText(QCoreApplication::translate("Timetable", "\344\277\235\345\255\230", nullptr));
        close->setText(QCoreApplication::translate("Timetable", "\345\205\263\351\227\255", nullptr));
        clear->setText(QCoreApplication::translate("Timetable", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Timetable: public Ui_Timetable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLE_H
