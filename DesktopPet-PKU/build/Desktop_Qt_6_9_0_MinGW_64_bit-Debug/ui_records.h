/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>

QT_BEGIN_NAMESPACE

class Ui_records
{
public:
    QGridLayout *gridLayout_8;
    QFrame *badmintonframe;
    QGridLayout *gridLayout_2;
    QLabel *runLabel_2;
    QLineEdit *badmintonTime;
    QLabel *label_3;
    QPushButton *badmintonBtn;
    QLabel *badmintonCalLabel;
    QFrame *basketballframe;
    QGridLayout *gridLayout_5;
    QPushButton *basketballBtn;
    QLabel *label_9;
    QLabel *runLabel_5;
    QLineEdit *basketballTime;
    QLabel *basketballCalLabel;
    QFrame *climbingframe;
    QGridLayout *gridLayout_9;
    QLabel *runLabel_9;
    QLineEdit *climbingTime;
    QLabel *label_17;
    QPushButton *climbingBtn;
    QLabel *climbingCalLabel;
    QFrame *tennisframe;
    QGridLayout *gridLayout_4;
    QPushButton *tennisBtn;
    QLineEdit *tennisTime;
    QLabel *label_7;
    QLabel *runLabel_4;
    QLabel *tennisCalLabel;
    QFrame *volleyballframe;
    QGridLayout *gridLayout_6;
    QLabel *label_11;
    QLineEdit *volleyballTime;
    QPushButton *volleyballBtn;
    QLabel *runLabel_6;
    QLabel *volleyCalLabel;
    QFrame *pingpongframe;
    QGridLayout *gridLayout_3;
    QLineEdit *pingpongTime;
    QLabel *runLabel_3;
    QLabel *label_5;
    QPushButton *pingpongBtn;
    QLabel *pingpongCalLabel;
    QFrame *runframe;
    QGridLayout *gridLayout;
    QLineEdit *runTimeEdit;
    QLabel *label;
    QPushButton *runButton;
    QLabel *label_2;
    QLabel *runLabel;
    QLineEdit *runDisEdit;
    QLabel *runCalLabel;
    QFrame *swimmingframe;
    QGridLayout *gridLayout_10;
    QLabel *label_19;
    QLabel *runLabel_10;
    QLineEdit *swimmingTime;
    QPushButton *swimmingBtn;
    QLabel *swimmingCalLabel;
    QFrame *footballframe;
    QGridLayout *gridLayout_7;
    QLineEdit *footballTime;
    QLabel *label_13;
    QPushButton *footballBtn;
    QLabel *runLabel_7;
    QLabel *footbalCalLabel;
    QFrame *ridingframe;
    QGridLayout *gridLayout_11;
    QLabel *runLabel_8;
    QLineEdit *ridingTime;
    QPushButton *ridingBtn;
    QLabel *label_15;
    QLabel *ridingCalLabel;
    QScrollBar *verticalScrollBar;

    void setupUi(QDialog *records)
    {
        if (records->objectName().isEmpty())
            records->setObjectName("records");
        records->resize(962, 618);
        gridLayout_8 = new QGridLayout(records);
        gridLayout_8->setObjectName("gridLayout_8");
        badmintonframe = new QFrame(records);
        badmintonframe->setObjectName("badmintonframe");
        badmintonframe->setFrameShape(QFrame::Shape::Panel);
        badmintonframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(badmintonframe);
        gridLayout_2->setObjectName("gridLayout_2");
        runLabel_2 = new QLabel(badmintonframe);
        runLabel_2->setObjectName("runLabel_2");

        gridLayout_2->addWidget(runLabel_2, 0, 0, 1, 1);

        badmintonTime = new QLineEdit(badmintonframe);
        badmintonTime->setObjectName("badmintonTime");

        gridLayout_2->addWidget(badmintonTime, 0, 1, 1, 1);

        label_3 = new QLabel(badmintonframe);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        badmintonBtn = new QPushButton(badmintonframe);
        badmintonBtn->setObjectName("badmintonBtn");

        gridLayout_2->addWidget(badmintonBtn, 0, 3, 1, 1);

        badmintonCalLabel = new QLabel(badmintonframe);
        badmintonCalLabel->setObjectName("badmintonCalLabel");

        gridLayout_2->addWidget(badmintonCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(badmintonframe, 0, 1, 1, 1);

        basketballframe = new QFrame(records);
        basketballframe->setObjectName("basketballframe");
        basketballframe->setFrameShape(QFrame::Shape::Panel);
        basketballframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_5 = new QGridLayout(basketballframe);
        gridLayout_5->setObjectName("gridLayout_5");
        basketballBtn = new QPushButton(basketballframe);
        basketballBtn->setObjectName("basketballBtn");

        gridLayout_5->addWidget(basketballBtn, 0, 3, 1, 1);

        label_9 = new QLabel(basketballframe);
        label_9->setObjectName("label_9");

        gridLayout_5->addWidget(label_9, 0, 2, 1, 1);

        runLabel_5 = new QLabel(basketballframe);
        runLabel_5->setObjectName("runLabel_5");

        gridLayout_5->addWidget(runLabel_5, 0, 0, 1, 1);

        basketballTime = new QLineEdit(basketballframe);
        basketballTime->setObjectName("basketballTime");

        gridLayout_5->addWidget(basketballTime, 0, 1, 1, 1);

        basketballCalLabel = new QLabel(basketballframe);
        basketballCalLabel->setObjectName("basketballCalLabel");

        gridLayout_5->addWidget(basketballCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(basketballframe, 2, 0, 1, 1);

        climbingframe = new QFrame(records);
        climbingframe->setObjectName("climbingframe");
        climbingframe->setFrameShape(QFrame::Shape::Panel);
        climbingframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_9 = new QGridLayout(climbingframe);
        gridLayout_9->setObjectName("gridLayout_9");
        runLabel_9 = new QLabel(climbingframe);
        runLabel_9->setObjectName("runLabel_9");

        gridLayout_9->addWidget(runLabel_9, 0, 0, 1, 1);

        climbingTime = new QLineEdit(climbingframe);
        climbingTime->setObjectName("climbingTime");

        gridLayout_9->addWidget(climbingTime, 0, 1, 1, 1);

        label_17 = new QLabel(climbingframe);
        label_17->setObjectName("label_17");

        gridLayout_9->addWidget(label_17, 0, 2, 1, 1);

        climbingBtn = new QPushButton(climbingframe);
        climbingBtn->setObjectName("climbingBtn");

        gridLayout_9->addWidget(climbingBtn, 0, 3, 1, 1);

        climbingCalLabel = new QLabel(climbingframe);
        climbingCalLabel->setObjectName("climbingCalLabel");

        gridLayout_9->addWidget(climbingCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(climbingframe, 4, 0, 1, 1);

        tennisframe = new QFrame(records);
        tennisframe->setObjectName("tennisframe");
        tennisframe->setFrameShape(QFrame::Shape::Panel);
        tennisframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(tennisframe);
        gridLayout_4->setObjectName("gridLayout_4");
        tennisBtn = new QPushButton(tennisframe);
        tennisBtn->setObjectName("tennisBtn");

        gridLayout_4->addWidget(tennisBtn, 0, 3, 1, 1);

        tennisTime = new QLineEdit(tennisframe);
        tennisTime->setObjectName("tennisTime");

        gridLayout_4->addWidget(tennisTime, 0, 1, 1, 1);

        label_7 = new QLabel(tennisframe);
        label_7->setObjectName("label_7");

        gridLayout_4->addWidget(label_7, 0, 2, 1, 1);

        runLabel_4 = new QLabel(tennisframe);
        runLabel_4->setObjectName("runLabel_4");

        gridLayout_4->addWidget(runLabel_4, 0, 0, 1, 1);

        tennisCalLabel = new QLabel(tennisframe);
        tennisCalLabel->setObjectName("tennisCalLabel");

        gridLayout_4->addWidget(tennisCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(tennisframe, 1, 1, 1, 1);

        volleyballframe = new QFrame(records);
        volleyballframe->setObjectName("volleyballframe");
        volleyballframe->setFrameShape(QFrame::Shape::Panel);
        volleyballframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_6 = new QGridLayout(volleyballframe);
        gridLayout_6->setObjectName("gridLayout_6");
        label_11 = new QLabel(volleyballframe);
        label_11->setObjectName("label_11");

        gridLayout_6->addWidget(label_11, 0, 2, 1, 1);

        volleyballTime = new QLineEdit(volleyballframe);
        volleyballTime->setObjectName("volleyballTime");

        gridLayout_6->addWidget(volleyballTime, 0, 1, 1, 1);

        volleyballBtn = new QPushButton(volleyballframe);
        volleyballBtn->setObjectName("volleyballBtn");

        gridLayout_6->addWidget(volleyballBtn, 0, 3, 1, 1);

        runLabel_6 = new QLabel(volleyballframe);
        runLabel_6->setObjectName("runLabel_6");

        gridLayout_6->addWidget(runLabel_6, 0, 0, 1, 1);

        volleyCalLabel = new QLabel(volleyballframe);
        volleyCalLabel->setObjectName("volleyCalLabel");

        gridLayout_6->addWidget(volleyCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(volleyballframe, 2, 1, 1, 1);

        pingpongframe = new QFrame(records);
        pingpongframe->setObjectName("pingpongframe");
        pingpongframe->setFrameShape(QFrame::Shape::Panel);
        pingpongframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_3 = new QGridLayout(pingpongframe);
        gridLayout_3->setObjectName("gridLayout_3");
        pingpongTime = new QLineEdit(pingpongframe);
        pingpongTime->setObjectName("pingpongTime");

        gridLayout_3->addWidget(pingpongTime, 0, 1, 1, 1);

        runLabel_3 = new QLabel(pingpongframe);
        runLabel_3->setObjectName("runLabel_3");

        gridLayout_3->addWidget(runLabel_3, 0, 0, 1, 1);

        label_5 = new QLabel(pingpongframe);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 0, 2, 1, 1);

        pingpongBtn = new QPushButton(pingpongframe);
        pingpongBtn->setObjectName("pingpongBtn");

        gridLayout_3->addWidget(pingpongBtn, 0, 3, 1, 1);

        pingpongCalLabel = new QLabel(pingpongframe);
        pingpongCalLabel->setObjectName("pingpongCalLabel");

        gridLayout_3->addWidget(pingpongCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(pingpongframe, 1, 0, 1, 1);

        runframe = new QFrame(records);
        runframe->setObjectName("runframe");
        runframe->setFrameShape(QFrame::Shape::Panel);
        runframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(runframe);
        gridLayout->setObjectName("gridLayout");
        runTimeEdit = new QLineEdit(runframe);
        runTimeEdit->setObjectName("runTimeEdit");
        runTimeEdit->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout->addWidget(runTimeEdit, 0, 1, 1, 1);

        label = new QLabel(runframe);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 2, 1, 1);

        runButton = new QPushButton(runframe);
        runButton->setObjectName("runButton");

        gridLayout->addWidget(runButton, 0, 3, 1, 1);

        label_2 = new QLabel(runframe);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        runLabel = new QLabel(runframe);
        runLabel->setObjectName("runLabel");

        gridLayout->addWidget(runLabel, 0, 0, 1, 1);

        runDisEdit = new QLineEdit(runframe);
        runDisEdit->setObjectName("runDisEdit");

        gridLayout->addWidget(runDisEdit, 1, 1, 1, 1);

        runCalLabel = new QLabel(runframe);
        runCalLabel->setObjectName("runCalLabel");

        gridLayout->addWidget(runCalLabel, 2, 1, 1, 1);


        gridLayout_8->addWidget(runframe, 0, 0, 1, 1);

        swimmingframe = new QFrame(records);
        swimmingframe->setObjectName("swimmingframe");
        swimmingframe->setFrameShape(QFrame::Shape::Panel);
        swimmingframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_10 = new QGridLayout(swimmingframe);
        gridLayout_10->setObjectName("gridLayout_10");
        label_19 = new QLabel(swimmingframe);
        label_19->setObjectName("label_19");

        gridLayout_10->addWidget(label_19, 0, 2, 1, 1);

        runLabel_10 = new QLabel(swimmingframe);
        runLabel_10->setObjectName("runLabel_10");

        gridLayout_10->addWidget(runLabel_10, 0, 0, 1, 1);

        swimmingTime = new QLineEdit(swimmingframe);
        swimmingTime->setObjectName("swimmingTime");

        gridLayout_10->addWidget(swimmingTime, 0, 1, 1, 1);

        swimmingBtn = new QPushButton(swimmingframe);
        swimmingBtn->setObjectName("swimmingBtn");

        gridLayout_10->addWidget(swimmingBtn, 0, 3, 1, 1);

        swimmingCalLabel = new QLabel(swimmingframe);
        swimmingCalLabel->setObjectName("swimmingCalLabel");

        gridLayout_10->addWidget(swimmingCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(swimmingframe, 4, 1, 1, 1);

        footballframe = new QFrame(records);
        footballframe->setObjectName("footballframe");
        footballframe->setFrameShape(QFrame::Shape::Panel);
        footballframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_7 = new QGridLayout(footballframe);
        gridLayout_7->setObjectName("gridLayout_7");
        footballTime = new QLineEdit(footballframe);
        footballTime->setObjectName("footballTime");

        gridLayout_7->addWidget(footballTime, 0, 1, 1, 1);

        label_13 = new QLabel(footballframe);
        label_13->setObjectName("label_13");

        gridLayout_7->addWidget(label_13, 0, 2, 1, 1);

        footballBtn = new QPushButton(footballframe);
        footballBtn->setObjectName("footballBtn");

        gridLayout_7->addWidget(footballBtn, 0, 3, 1, 1);

        runLabel_7 = new QLabel(footballframe);
        runLabel_7->setObjectName("runLabel_7");

        gridLayout_7->addWidget(runLabel_7, 0, 0, 1, 1);

        footbalCalLabel = new QLabel(footballframe);
        footbalCalLabel->setObjectName("footbalCalLabel");

        gridLayout_7->addWidget(footbalCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(footballframe, 3, 0, 1, 1);

        ridingframe = new QFrame(records);
        ridingframe->setObjectName("ridingframe");
        ridingframe->setFrameShape(QFrame::Shape::Panel);
        ridingframe->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_11 = new QGridLayout(ridingframe);
        gridLayout_11->setObjectName("gridLayout_11");
        runLabel_8 = new QLabel(ridingframe);
        runLabel_8->setObjectName("runLabel_8");

        gridLayout_11->addWidget(runLabel_8, 0, 0, 1, 1);

        ridingTime = new QLineEdit(ridingframe);
        ridingTime->setObjectName("ridingTime");

        gridLayout_11->addWidget(ridingTime, 0, 1, 1, 1);

        ridingBtn = new QPushButton(ridingframe);
        ridingBtn->setObjectName("ridingBtn");

        gridLayout_11->addWidget(ridingBtn, 0, 3, 1, 1);

        label_15 = new QLabel(ridingframe);
        label_15->setObjectName("label_15");

        gridLayout_11->addWidget(label_15, 0, 2, 1, 1);

        ridingCalLabel = new QLabel(ridingframe);
        ridingCalLabel->setObjectName("ridingCalLabel");

        gridLayout_11->addWidget(ridingCalLabel, 1, 1, 1, 1);


        gridLayout_8->addWidget(ridingframe, 3, 1, 1, 1);

        verticalScrollBar = new QScrollBar(records);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);

        gridLayout_8->addWidget(verticalScrollBar, 0, 2, 5, 1);


        retranslateUi(records);

        QMetaObject::connectSlotsByName(records);
    } // setupUi

    void retranslateUi(QDialog *records)
    {
        records->setWindowTitle(QCoreApplication::translate("records", "\350\277\220\345\212\250\350\256\260\345\275\225", nullptr));
        runLabel_2->setText(QCoreApplication::translate("records", "\347\276\275\346\257\233\347\220\203", nullptr));
        badmintonTime->setText(QString());
        badmintonTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        badmintonBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        badmintonCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        basketballBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        label_9->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        runLabel_5->setText(QCoreApplication::translate("records", "\347\257\256\347\220\203", nullptr));
        basketballTime->setText(QString());
        basketballTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        basketballCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        runLabel_9->setText(QCoreApplication::translate("records", "\347\231\273\345\261\261", nullptr));
        climbingTime->setText(QString());
        climbingTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        label_17->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        climbingBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        climbingCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        tennisBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        tennisTime->setText(QString());
        tennisTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        label_7->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        runLabel_4->setText(QCoreApplication::translate("records", "\347\275\221\347\220\203", nullptr));
        tennisCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        label_11->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        volleyballTime->setText(QString());
        volleyballTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        volleyballBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        runLabel_6->setText(QCoreApplication::translate("records", "\346\216\222\347\220\203", nullptr));
        volleyCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        pingpongTime->setText(QString());
        pingpongTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        runLabel_3->setText(QCoreApplication::translate("records", "\344\271\222\344\271\223\347\220\203", nullptr));
        label_5->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        pingpongBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        pingpongCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        runTimeEdit->setText(QString());
        runTimeEdit->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        runButton->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("records", "\345\215\203\347\261\263", nullptr));
        runLabel->setText(QCoreApplication::translate("records", "\350\267\221\346\255\245", nullptr));
        runDisEdit->setText(QString());
        runDisEdit->setPlaceholderText(QCoreApplication::translate("records", "\351\207\214\347\250\213", nullptr));
        runCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        label_19->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        runLabel_10->setText(QCoreApplication::translate("records", "\346\270\270\346\263\263", nullptr));
        swimmingTime->setText(QString());
        swimmingTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        swimmingBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        swimmingCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        footballTime->setText(QString());
        footballTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        label_13->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        footballBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        runLabel_7->setText(QCoreApplication::translate("records", "\350\266\263\347\220\203", nullptr));
        footbalCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
        runLabel_8->setText(QCoreApplication::translate("records", "\351\252\221\350\241\214", nullptr));
        ridingTime->setText(QString());
        ridingTime->setPlaceholderText(QCoreApplication::translate("records", "\346\227\266\351\227\264", nullptr));
        ridingBtn->setText(QCoreApplication::translate("records", "\350\256\260\345\275\225", nullptr));
        label_15->setText(QCoreApplication::translate("records", "\345\210\206\351\222\237", nullptr));
        ridingCalLabel->setText(QCoreApplication::translate("records", "\351\242\204\350\256\241\346\266\210\350\200\227: 0 \345\215\241\350\267\257\351\207\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class records: public Ui_records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
