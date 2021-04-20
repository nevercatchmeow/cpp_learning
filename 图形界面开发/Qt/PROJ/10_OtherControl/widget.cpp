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

    // QLabel 显示图片
    ui->label_img->setPixmap(QPixmap(":/Image/Frame.jpg"));
    // QLabel 显示动画
    QMovie *movie = new QMovie(":/Image/mario.gif");
    ui->label_movie->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

