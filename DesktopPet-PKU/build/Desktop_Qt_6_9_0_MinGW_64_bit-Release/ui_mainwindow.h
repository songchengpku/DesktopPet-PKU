/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *timetable;
    QPushButton *sportmanagement;
    QPushButton *shedule;
    QPushButton *close;
    QGraphicsView *pet;
    QPushButton *dressing;
    QPushButton *eating;
    QPushButton *bathing;
    QProgressBar *satiety;
    QProgressBar *cleanliness;
    QProgressBar *favorability;
    QLabel *satietylabel;
    QLabel *satietylabel_2;
    QLabel *satietylabel_3;
    QPushButton *chatButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(240, 321);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        timetable = new QPushButton(centralwidget);
        timetable->setObjectName("timetable");
        timetable->setGeometry(QRect(40, 60, 20, 60));
        sportmanagement = new QPushButton(centralwidget);
        sportmanagement->setObjectName("sportmanagement");
        sportmanagement->setGeometry(QRect(90, 10, 60, 20));
        shedule = new QPushButton(centralwidget);
        shedule->setObjectName("shedule");
        shedule->setGeometry(QRect(180, 60, 20, 60));
        close = new QPushButton(centralwidget);
        close->setObjectName("close");
        close->setGeometry(QRect(180, 140, 18, 18));
        pet = new QGraphicsView(centralwidget);
        pet->setObjectName("pet");
        pet->setGeometry(QRect(60, 30, 121, 111));
        dressing = new QPushButton(centralwidget);
        dressing->setObjectName("dressing");
        dressing->setGeometry(QRect(150, 150, 30, 30));
        eating = new QPushButton(centralwidget);
        eating->setObjectName("eating");
        eating->setGeometry(QRect(60, 150, 30, 30));
        bathing = new QPushButton(centralwidget);
        bathing->setObjectName("bathing");
        bathing->setGeometry(QRect(105, 160, 30, 30));
        satiety = new QProgressBar(centralwidget);
        satiety->setObjectName("satiety");
        satiety->setGeometry(QRect(80, 200, 120, 20));
        satiety->setValue(24);
        cleanliness = new QProgressBar(centralwidget);
        cleanliness->setObjectName("cleanliness");
        cleanliness->setGeometry(QRect(80, 220, 120, 20));
        cleanliness->setValue(24);
        favorability = new QProgressBar(centralwidget);
        favorability->setObjectName("favorability");
        favorability->setGeometry(QRect(80, 240, 120, 20));
        favorability->setValue(24);
        satietylabel = new QLabel(centralwidget);
        satietylabel->setObjectName("satietylabel");
        satietylabel->setGeometry(QRect(40, 200, 40, 15));
        satietylabel_2 = new QLabel(centralwidget);
        satietylabel_2->setObjectName("satietylabel_2");
        satietylabel_2->setGeometry(QRect(40, 220, 40, 15));
        satietylabel_3 = new QLabel(centralwidget);
        satietylabel_3->setObjectName("satietylabel_3");
        satietylabel_3->setGeometry(QRect(40, 240, 40, 15));
        chatButton = new QPushButton(centralwidget);
        chatButton->setObjectName("chatButton");
        chatButton->setGeometry(QRect(170, 10, 61, 21));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MailMarkRead));
        chatButton->setIcon(icon);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 240, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        timetable->setText(QCoreApplication::translate("MainWindow", "\350\257\276\n"
"\347\250\213\n"
"\350\241\250", nullptr));
        sportmanagement->setText(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\347\256\241\347\220\206", nullptr));
        shedule->setText(QCoreApplication::translate("MainWindow", "\345\244\207\n"
"\345\277\230\n"
"\345\275\225", nullptr));
        close->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
#if QT_CONFIG(whatsthis)
        pet->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>uhvbwdo</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        dressing->setText(QString());
        eating->setText(QString());
        bathing->setText(QString());
        satietylabel->setText(QCoreApplication::translate("MainWindow", "\351\245\261\350\205\271\345\272\246", nullptr));
        satietylabel_2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\346\264\201\345\272\246", nullptr));
        satietylabel_3->setText(QCoreApplication::translate("MainWindow", "\345\245\275\346\204\237\345\272\246", nullptr));
        chatButton->setText(QCoreApplication::translate("MainWindow", "chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
