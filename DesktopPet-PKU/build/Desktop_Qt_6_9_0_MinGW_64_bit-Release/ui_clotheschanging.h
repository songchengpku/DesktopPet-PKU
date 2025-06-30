/********************************************************************************
** Form generated from reading UI file 'clotheschanging.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOTHESCHANGING_H
#define UI_CLOTHESCHANGING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClothesChanging
{
public:
    QPushButton *complete;
    QPushButton *suit1;
    QPushButton *suit3;
    QPushButton *suit2;
    QPushButton *suit4;
    QGraphicsView *lock2;
    QGraphicsView *lock3;
    QGraphicsView *lock4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *ClothesChanging)
    {
        if (ClothesChanging->objectName().isEmpty())
            ClothesChanging->setObjectName("ClothesChanging");
        ClothesChanging->resize(410, 350);
        QFont font;
        font.setBold(true);
        ClothesChanging->setFont(font);
        complete = new QPushButton(ClothesChanging);
        complete->setObjectName("complete");
        complete->setGeometry(QRect(310, 300, 75, 24));
        suit1 = new QPushButton(ClothesChanging);
        suit1->setObjectName("suit1");
        suit1->setGeometry(QRect(70, 50, 100, 100));
        suit3 = new QPushButton(ClothesChanging);
        suit3->setObjectName("suit3");
        suit3->setGeometry(QRect(70, 180, 100, 100));
        suit2 = new QPushButton(ClothesChanging);
        suit2->setObjectName("suit2");
        suit2->setGeometry(QRect(240, 50, 100, 100));
        suit4 = new QPushButton(ClothesChanging);
        suit4->setObjectName("suit4");
        suit4->setGeometry(QRect(240, 180, 100, 100));
        lock2 = new QGraphicsView(ClothesChanging);
        lock2->setObjectName("lock2");
        lock2->setGeometry(QRect(240, 50, 100, 100));
        lock3 = new QGraphicsView(ClothesChanging);
        lock3->setObjectName("lock3");
        lock3->setGeometry(QRect(70, 180, 100, 100));
        lock4 = new QGraphicsView(ClothesChanging);
        lock4->setObjectName("lock4");
        lock4->setGeometry(QRect(240, 180, 100, 100));
        label = new QLabel(ClothesChanging);
        label->setObjectName("label");
        label->setGeometry(QRect(95, 150, 54, 16));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(ClothesChanging);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(265, 150, 54, 16));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(ClothesChanging);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(95, 280, 54, 16));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(ClothesChanging);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(265, 280, 54, 16));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(ClothesChanging);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(145, 10, 121, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(ClothesChanging);

        QMetaObject::connectSlotsByName(ClothesChanging);
    } // setupUi

    void retranslateUi(QDialog *ClothesChanging)
    {
        ClothesChanging->setWindowTitle(QCoreApplication::translate("ClothesChanging", "Dialog", nullptr));
        complete->setText(QCoreApplication::translate("ClothesChanging", "\345\256\214\346\210\220", nullptr));
        suit1->setText(QString());
        suit3->setText(QString());
        suit2->setText(QString());
        suit4->setText(QString());
        label->setText(QCoreApplication::translate("ClothesChanging", "\347\273\217\345\205\270\351\243\216", nullptr));
        label_2->setText(QCoreApplication::translate("ClothesChanging", "\345\267\245\344\275\234\351\243\216", nullptr));
        label_3->setText(QCoreApplication::translate("ClothesChanging", "\350\277\220\345\212\250\351\243\216", nullptr));
        label_4->setText(QCoreApplication::translate("ClothesChanging", "\345\255\246\351\231\242\351\243\216", nullptr));
        label_5->setText(QCoreApplication::translate("ClothesChanging", "\347\232\256\350\202\244\346\251\261\347\252\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClothesChanging: public Ui_ClothesChanging {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOTHESCHANGING_H
