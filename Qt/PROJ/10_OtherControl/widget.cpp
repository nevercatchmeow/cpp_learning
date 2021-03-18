#include "widget.h"
#include "ui_widget.h"

#include <QLabel>
#include <QPixmap>
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Stacked Widget
    connect(ui->btn_ScrollArea, &QPushButton::clicked, [=](){
       ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btn_ToolBox, &QPushButton::clicked, [=](){
       ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btn_TabWidget, &QPushButton::clicked, [=](){
       ui->stackedWidget->setCurrentIndex(2);
    });

    // 下拉框
    ui->comboBox->addItem("C");
    ui->comboBox->addItem("D");
    ui->comboBox->addItem("E");
    ui->comboBox->addItem("F");

    connect(ui->btn_ChooseE, &QPushButton::clicked, [=](){
        // ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("E");
    });

    // QLable 显示图片
//    ui->label->setPixmap(QPixmap(":/image/Sunny.jpg"));

    ui->label->setStyleSheet(QString::fromUtf8("image:url(:/image/Sunny.jpg);"));


}

Widget::~Widget()
{
    delete ui;
}

