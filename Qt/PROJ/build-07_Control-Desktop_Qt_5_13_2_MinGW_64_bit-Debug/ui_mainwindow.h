/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox_Event;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtn_Mountain;
    QRadioButton *rbtn_Rain;
    QGroupBox *groupBox_Person;
    QRadioButton *rbtn_Zuodao;
    QRadioButton *rbtn_Baiye;
    QGroupBox *groupBox_Skill;
    QGridLayout *gridLayout;
    QCheckBox *cbtn_Stealth;
    QCheckBox *cbtn_Bomb;
    QCheckBox *cbtn_Run;
    QListWidget *listWidget1;
    QListWidget *listWidget2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 80, 100, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Luffy.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(100, 120, 100, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/LuffyQ.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        groupBox_Event = new QGroupBox(centralwidget);
        groupBox_Event->setObjectName(QString::fromUtf8("groupBox_Event"));
        groupBox_Event->setGeometry(QRect(160, 170, 67, 70));
        verticalLayout = new QVBoxLayout(groupBox_Event);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbtn_Mountain = new QRadioButton(groupBox_Event);
        rbtn_Mountain->setObjectName(QString::fromUtf8("rbtn_Mountain"));

        verticalLayout->addWidget(rbtn_Mountain);

        rbtn_Rain = new QRadioButton(groupBox_Event);
        rbtn_Rain->setObjectName(QString::fromUtf8("rbtn_Rain"));

        verticalLayout->addWidget(rbtn_Rain);

        groupBox_Person = new QGroupBox(centralwidget);
        groupBox_Person->setObjectName(QString::fromUtf8("groupBox_Person"));
        groupBox_Person->setGeometry(QRect(80, 170, 71, 70));
        rbtn_Zuodao = new QRadioButton(groupBox_Person);
        rbtn_Zuodao->setObjectName(QString::fromUtf8("rbtn_Zuodao"));
        rbtn_Zuodao->setGeometry(QRect(10, 22, 51, 16));
        rbtn_Baiye = new QRadioButton(groupBox_Person);
        rbtn_Baiye->setObjectName(QString::fromUtf8("rbtn_Baiye"));
        rbtn_Baiye->setGeometry(QRect(10, 44, 51, 16));
        groupBox_Skill = new QGroupBox(centralwidget);
        groupBox_Skill->setObjectName(QString::fromUtf8("groupBox_Skill"));
        groupBox_Skill->setGeometry(QRect(90, 250, 91, 92));
        gridLayout = new QGridLayout(groupBox_Skill);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbtn_Stealth = new QCheckBox(groupBox_Skill);
        cbtn_Stealth->setObjectName(QString::fromUtf8("cbtn_Stealth"));

        gridLayout->addWidget(cbtn_Stealth, 0, 0, 1, 1);

        cbtn_Bomb = new QCheckBox(groupBox_Skill);
        cbtn_Bomb->setObjectName(QString::fromUtf8("cbtn_Bomb"));

        gridLayout->addWidget(cbtn_Bomb, 1, 0, 1, 1);

        cbtn_Run = new QCheckBox(groupBox_Skill);
        cbtn_Run->setObjectName(QString::fromUtf8("cbtn_Run"));

        gridLayout->addWidget(cbtn_Run, 2, 0, 1, 1);

        listWidget1 = new QListWidget(centralwidget);
        listWidget1->setObjectName(QString::fromUtf8("listWidget1"));
        listWidget1->setGeometry(QRect(380, 40, 251, 71));
        listWidget2 = new QListWidget(centralwidget);
        listWidget2->setObjectName(QString::fromUtf8("listWidget2"));
        listWidget2->setGeometry(QRect(380, 140, 256, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Push Button", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "Tool Button", nullptr));
        groupBox_Event->setTitle(QCoreApplication::translate("MainWindow", "\344\272\213\344\273\266", nullptr));
        rbtn_Mountain->setText(QCoreApplication::translate("MainWindow", "\350\247\202\345\261\261", nullptr));
        rbtn_Rain->setText(QCoreApplication::translate("MainWindow", "\345\220\254\351\233\250", nullptr));
        groupBox_Person->setTitle(QCoreApplication::translate("MainWindow", "\350\247\222\350\211\262", nullptr));
        rbtn_Zuodao->setText(QCoreApplication::translate("MainWindow", "\345\267\246\351\201\223", nullptr));
        rbtn_Baiye->setText(QCoreApplication::translate("MainWindow", "\347\231\275\351\207\216", nullptr));
        groupBox_Skill->setTitle(QCoreApplication::translate("MainWindow", "\346\212\200\350\203\275\351\200\211\346\213\251", nullptr));
        cbtn_Stealth->setText(QCoreApplication::translate("MainWindow", "\345\256\214\347\276\216\351\232\220\350\272\253", nullptr));
        cbtn_Bomb->setText(QCoreApplication::translate("MainWindow", "\350\230\221\350\217\207\347\202\270\345\274\271", nullptr));
        cbtn_Run->setText(QCoreApplication::translate("MainWindow", "\350\267\221\345\277\253\345\277\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
