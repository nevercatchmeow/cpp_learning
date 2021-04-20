#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->ptn_set, &QPushButton::clicked, [=](){
        ui->widget->setData(50);
    });

    connect(ui->ptn_get, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getData();
    });
}

Widget::~Widget()
{
    delete ui;
}

