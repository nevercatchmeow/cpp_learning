#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidgetItem>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rbtn_Zuodao->setChecked(true);
    ui->rbtn_Mountain->setChecked(true);

    // 选中事件"听雨"时打印
    connect(ui->rbtn_Rain, &QRadioButton::clicked, [=](){
        qDebug() << "听雨...";
    });


    // 选中技能"蘑菇炮弹"时打印
    connect(ui->cbtn_Bomb, &QCheckBox::stateChanged, [=](int status){
        qDebug() << "蘑菇炮弹!!!" << status;
    });

    // QListWidgetItem
    QListWidgetItem * item1 = new QListWidgetItem("人生到处知何似");
    QListWidgetItem * item2 = new QListWidgetItem("应似飞鸿踏雪泥");

    // 文本居中
    item1->setTextAlignment(Qt::AlignCenter);
    item2->setTextAlignment(Qt::AlignCenter);
    // 将QListWidgetItem加入QListWidget
    ui->listWidget1->addItem(item1);
    ui->listWidget1->addItem(item2);

    // QStringList => QList<QString> => list<String>
    // 使用 QStringList 一次添加多行。
    QStringList list;
    list << "人生到处知何似" << "应似飞鸿踏雪泥";
    ui->listWidget2->addItems(list);


}

MainWindow::~MainWindow()
{
    delete ui;
}

