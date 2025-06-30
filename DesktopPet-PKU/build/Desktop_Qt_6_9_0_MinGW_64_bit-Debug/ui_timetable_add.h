/********************************************************************************
** Form generated from reading UI file 'timetable_add.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLE_ADD_H
#define UI_TIMETABLE_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Timetable_add
{
public:
    QPushButton *complete;
    QLineEdit *name;
    QLabel *label;
    QLineEdit *message;
    QLabel *label_2;
    QComboBox *weekday1;
    QComboBox *time11;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *weekday2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *weekday3;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QComboBox *weekday4;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QComboBox *time21;
    QComboBox *time31;
    QComboBox *time41;
    QComboBox *time42;
    QComboBox *time32;
    QComboBox *time22;
    QComboBox *time12;

    void setupUi(QDialog *Timetable_add)
    {
        if (Timetable_add->objectName().isEmpty())
            Timetable_add->setObjectName("Timetable_add");
        Timetable_add->resize(400, 600);
        complete = new QPushButton(Timetable_add);
        complete->setObjectName("complete");
        complete->setGeometry(QRect(300, 520, 48, 48));
        name = new QLineEdit(Timetable_add);
        name->setObjectName("name");
        name->setGeometry(QRect(170, 70, 120, 25));
        label = new QLabel(Timetable_add);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 70, 60, 25));
        message = new QLineEdit(Timetable_add);
        message->setObjectName("message");
        message->setGeometry(QRect(170, 120, 120, 25));
        label_2 = new QLabel(Timetable_add);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 120, 60, 25));
        weekday1 = new QComboBox(Timetable_add);
        weekday1->addItem(QString());
        weekday1->addItem(QString());
        weekday1->addItem(QString());
        weekday1->addItem(QString());
        weekday1->addItem(QString());
        weekday1->addItem(QString());
        weekday1->addItem(QString());
        weekday1->addItem(QString());
        weekday1->setObjectName("weekday1");
        weekday1->setGeometry(QRect(90, 210, 50, 24));
        time11 = new QComboBox(Timetable_add);
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->addItem(QString());
        time11->setObjectName("time11");
        time11->setGeometry(QRect(180, 210, 50, 25));
        label_3 = new QLabel(Timetable_add);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 210, 75, 24));
        label_4 = new QLabel(Timetable_add);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 210, 15, 24));
        label_5 = new QLabel(Timetable_add);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 210, 15, 24));
        label_6 = new QLabel(Timetable_add);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(360, 210, 15, 24));
        label_7 = new QLabel(Timetable_add);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(280, 210, 15, 24));
        label_8 = new QLabel(Timetable_add);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(260, 210, 15, 24));
        weekday2 = new QComboBox(Timetable_add);
        weekday2->addItem(QString());
        weekday2->addItem(QString());
        weekday2->addItem(QString());
        weekday2->addItem(QString());
        weekday2->addItem(QString());
        weekday2->addItem(QString());
        weekday2->addItem(QString());
        weekday2->addItem(QString());
        weekday2->setObjectName("weekday2");
        weekday2->setGeometry(QRect(90, 260, 50, 24));
        label_9 = new QLabel(Timetable_add);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 260, 75, 24));
        label_10 = new QLabel(Timetable_add);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(240, 260, 15, 24));
        label_11 = new QLabel(Timetable_add);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(360, 260, 15, 24));
        label_12 = new QLabel(Timetable_add);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(160, 260, 15, 24));
        label_13 = new QLabel(Timetable_add);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(280, 260, 15, 24));
        label_14 = new QLabel(Timetable_add);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(260, 260, 15, 24));
        weekday3 = new QComboBox(Timetable_add);
        weekday3->addItem(QString());
        weekday3->addItem(QString());
        weekday3->addItem(QString());
        weekday3->addItem(QString());
        weekday3->addItem(QString());
        weekday3->addItem(QString());
        weekday3->addItem(QString());
        weekday3->addItem(QString());
        weekday3->setObjectName("weekday3");
        weekday3->setGeometry(QRect(90, 310, 50, 24));
        label_15 = new QLabel(Timetable_add);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 310, 75, 24));
        label_16 = new QLabel(Timetable_add);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(240, 310, 15, 24));
        label_17 = new QLabel(Timetable_add);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(360, 310, 15, 24));
        label_18 = new QLabel(Timetable_add);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(160, 310, 15, 24));
        label_19 = new QLabel(Timetable_add);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(280, 310, 15, 24));
        label_20 = new QLabel(Timetable_add);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(260, 310, 15, 24));
        weekday4 = new QComboBox(Timetable_add);
        weekday4->addItem(QString());
        weekday4->addItem(QString());
        weekday4->addItem(QString());
        weekday4->addItem(QString());
        weekday4->addItem(QString());
        weekday4->addItem(QString());
        weekday4->addItem(QString());
        weekday4->addItem(QString());
        weekday4->setObjectName("weekday4");
        weekday4->setGeometry(QRect(90, 360, 50, 24));
        label_21 = new QLabel(Timetable_add);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(10, 360, 75, 24));
        label_22 = new QLabel(Timetable_add);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(240, 360, 15, 24));
        label_23 = new QLabel(Timetable_add);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(360, 360, 15, 24));
        label_24 = new QLabel(Timetable_add);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(160, 360, 15, 24));
        label_25 = new QLabel(Timetable_add);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(280, 360, 15, 24));
        label_26 = new QLabel(Timetable_add);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(260, 360, 15, 24));
        time21 = new QComboBox(Timetable_add);
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->addItem(QString());
        time21->setObjectName("time21");
        time21->setGeometry(QRect(180, 260, 50, 25));
        time31 = new QComboBox(Timetable_add);
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->addItem(QString());
        time31->setObjectName("time31");
        time31->setGeometry(QRect(180, 310, 50, 25));
        time41 = new QComboBox(Timetable_add);
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->addItem(QString());
        time41->setObjectName("time41");
        time41->setGeometry(QRect(180, 360, 50, 25));
        time42 = new QComboBox(Timetable_add);
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->addItem(QString());
        time42->setObjectName("time42");
        time42->setGeometry(QRect(300, 360, 50, 25));
        time32 = new QComboBox(Timetable_add);
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->addItem(QString());
        time32->setObjectName("time32");
        time32->setGeometry(QRect(300, 310, 50, 25));
        time22 = new QComboBox(Timetable_add);
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->addItem(QString());
        time22->setObjectName("time22");
        time22->setGeometry(QRect(300, 260, 50, 25));
        time12 = new QComboBox(Timetable_add);
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->addItem(QString());
        time12->setObjectName("time12");
        time12->setGeometry(QRect(300, 210, 50, 25));

        retranslateUi(Timetable_add);

        QMetaObject::connectSlotsByName(Timetable_add);
    } // setupUi

    void retranslateUi(QDialog *Timetable_add)
    {
        Timetable_add->setWindowTitle(QCoreApplication::translate("Timetable_add", "\346\267\273\345\212\240\350\257\276\347\250\213", nullptr));
        complete->setText(QCoreApplication::translate("Timetable_add", "\345\256\214\346\210\220", nullptr));
        label->setText(QCoreApplication::translate("Timetable_add", "\350\257\276\347\250\213\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Timetable_add", "\350\257\276\347\250\213\344\277\241\346\201\257\357\274\232", nullptr));
        weekday1->setItemText(0, QString());
        weekday1->setItemText(1, QCoreApplication::translate("Timetable_add", "\344\270\200", nullptr));
        weekday1->setItemText(2, QCoreApplication::translate("Timetable_add", "\344\272\214", nullptr));
        weekday1->setItemText(3, QCoreApplication::translate("Timetable_add", "\344\270\211", nullptr));
        weekday1->setItemText(4, QCoreApplication::translate("Timetable_add", "\345\233\233", nullptr));
        weekday1->setItemText(5, QCoreApplication::translate("Timetable_add", "\344\272\224", nullptr));
        weekday1->setItemText(6, QCoreApplication::translate("Timetable_add", "\345\205\255", nullptr));
        weekday1->setItemText(7, QCoreApplication::translate("Timetable_add", "\346\227\245", nullptr));

        time11->setItemText(0, QString());
        time11->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time11->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time11->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time11->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time11->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time11->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time11->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time11->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time11->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time11->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time11->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time11->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

        label_3->setText(QCoreApplication::translate("Timetable_add", "\346\227\266\346\256\265\344\270\200\357\274\232\346\230\237\346\234\237", nullptr));
        label_4->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_5->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_6->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_7->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_8->setText(QCoreApplication::translate("Timetable_add", "~", nullptr));
        weekday2->setItemText(0, QString());
        weekday2->setItemText(1, QCoreApplication::translate("Timetable_add", "\344\270\200", nullptr));
        weekday2->setItemText(2, QCoreApplication::translate("Timetable_add", "\344\272\214", nullptr));
        weekday2->setItemText(3, QCoreApplication::translate("Timetable_add", "\344\270\211", nullptr));
        weekday2->setItemText(4, QCoreApplication::translate("Timetable_add", "\345\233\233", nullptr));
        weekday2->setItemText(5, QCoreApplication::translate("Timetable_add", "\344\272\224", nullptr));
        weekday2->setItemText(6, QCoreApplication::translate("Timetable_add", "\345\205\255", nullptr));
        weekday2->setItemText(7, QCoreApplication::translate("Timetable_add", "\346\227\245", nullptr));

        label_9->setText(QCoreApplication::translate("Timetable_add", "\346\227\266\346\256\265\344\272\214\357\274\232\346\230\237\346\234\237", nullptr));
        label_10->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_11->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_12->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_13->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_14->setText(QCoreApplication::translate("Timetable_add", "~", nullptr));
        weekday3->setItemText(0, QString());
        weekday3->setItemText(1, QCoreApplication::translate("Timetable_add", "\344\270\200", nullptr));
        weekday3->setItemText(2, QCoreApplication::translate("Timetable_add", "\344\272\214", nullptr));
        weekday3->setItemText(3, QCoreApplication::translate("Timetable_add", "\344\270\211", nullptr));
        weekday3->setItemText(4, QCoreApplication::translate("Timetable_add", "\345\233\233", nullptr));
        weekday3->setItemText(5, QCoreApplication::translate("Timetable_add", "\344\272\224", nullptr));
        weekday3->setItemText(6, QCoreApplication::translate("Timetable_add", "\345\205\255", nullptr));
        weekday3->setItemText(7, QCoreApplication::translate("Timetable_add", "\346\227\245", nullptr));

        label_15->setText(QCoreApplication::translate("Timetable_add", "\346\227\266\346\256\265\344\270\211\357\274\232\346\230\237\346\234\237", nullptr));
        label_16->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_17->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_18->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_19->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_20->setText(QCoreApplication::translate("Timetable_add", "~", nullptr));
        weekday4->setItemText(0, QString());
        weekday4->setItemText(1, QCoreApplication::translate("Timetable_add", "\344\270\200", nullptr));
        weekday4->setItemText(2, QCoreApplication::translate("Timetable_add", "\344\272\214", nullptr));
        weekday4->setItemText(3, QCoreApplication::translate("Timetable_add", "\344\270\211", nullptr));
        weekday4->setItemText(4, QCoreApplication::translate("Timetable_add", "\345\233\233", nullptr));
        weekday4->setItemText(5, QCoreApplication::translate("Timetable_add", "\344\272\224", nullptr));
        weekday4->setItemText(6, QCoreApplication::translate("Timetable_add", "\345\205\255", nullptr));
        weekday4->setItemText(7, QCoreApplication::translate("Timetable_add", "\346\227\245", nullptr));

        label_21->setText(QCoreApplication::translate("Timetable_add", "\346\227\266\346\256\265\345\233\233\357\274\232\346\230\237\346\234\237", nullptr));
        label_22->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_23->setText(QCoreApplication::translate("Timetable_add", "\350\212\202", nullptr));
        label_24->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_25->setText(QCoreApplication::translate("Timetable_add", "\347\254\254", nullptr));
        label_26->setText(QCoreApplication::translate("Timetable_add", "~", nullptr));
        time21->setItemText(0, QString());
        time21->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time21->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time21->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time21->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time21->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time21->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time21->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time21->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time21->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time21->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time21->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time21->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

        time31->setItemText(0, QString());
        time31->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time31->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time31->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time31->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time31->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time31->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time31->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time31->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time31->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time31->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time31->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time31->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

        time41->setItemText(0, QString());
        time41->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time41->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time41->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time41->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time41->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time41->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time41->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time41->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time41->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time41->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time41->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time41->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

        time42->setItemText(0, QString());
        time42->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time42->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time42->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time42->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time42->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time42->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time42->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time42->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time42->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time42->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time42->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time42->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

        time32->setItemText(0, QString());
        time32->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time32->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time32->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time32->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time32->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time32->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time32->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time32->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time32->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time32->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time32->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time32->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

        time22->setItemText(0, QString());
        time22->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time22->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time22->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time22->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time22->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time22->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time22->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time22->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time22->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time22->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time22->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time22->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

        time12->setItemText(0, QString());
        time12->setItemText(1, QCoreApplication::translate("Timetable_add", "1", nullptr));
        time12->setItemText(2, QCoreApplication::translate("Timetable_add", "2", nullptr));
        time12->setItemText(3, QCoreApplication::translate("Timetable_add", "3", nullptr));
        time12->setItemText(4, QCoreApplication::translate("Timetable_add", "4", nullptr));
        time12->setItemText(5, QCoreApplication::translate("Timetable_add", "5", nullptr));
        time12->setItemText(6, QCoreApplication::translate("Timetable_add", "6", nullptr));
        time12->setItemText(7, QCoreApplication::translate("Timetable_add", "7", nullptr));
        time12->setItemText(8, QCoreApplication::translate("Timetable_add", "8", nullptr));
        time12->setItemText(9, QCoreApplication::translate("Timetable_add", "9", nullptr));
        time12->setItemText(10, QCoreApplication::translate("Timetable_add", "10", nullptr));
        time12->setItemText(11, QCoreApplication::translate("Timetable_add", "11", nullptr));
        time12->setItemText(12, QCoreApplication::translate("Timetable_add", "12", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Timetable_add: public Ui_Timetable_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLE_ADD_H
