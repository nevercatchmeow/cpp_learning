/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    MyLabel *label_mouse;
    QLabel *label_timer_1;
    QLabel *label_timer_2;
    QLabel *label_timer_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(183, 319);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_mouse = new MyLabel(Widget);
        label_mouse->setObjectName(QString::fromUtf8("label_mouse"));
        label_mouse->setFrameShape(QFrame::Box);
        label_mouse->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_mouse);

        label_timer_1 = new QLabel(Widget);
        label_timer_1->setObjectName(QString::fromUtf8("label_timer_1"));
        label_timer_1->setFrameShape(QFrame::Box);
        label_timer_1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_timer_1);

        label_timer_2 = new QLabel(Widget);
        label_timer_2->setObjectName(QString::fromUtf8("label_timer_2"));
        label_timer_2->setFrameShape(QFrame::Box);
        label_timer_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_timer_2);

        label_timer_3 = new QLabel(Widget);
        label_timer_3->setObjectName(QString::fromUtf8("label_timer_3"));
        label_timer_3->setFrameShape(QFrame::Box);
        label_timer_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_timer_3);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_mouse->setText(QCoreApplication::translate("Widget", "\347\202\271\346\210\221\345\221\200\357\274\201", nullptr));
        label_timer_1->setText(QString());
        label_timer_2->setText(QString());
        label_timer_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "STOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
