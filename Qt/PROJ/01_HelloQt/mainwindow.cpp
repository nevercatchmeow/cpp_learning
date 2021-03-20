#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

#include "mypushbutton.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 重置窗口大小
    // resize(600, 400);
    // 设置窗口标题
    setWindowTitle("First Window");
    // 设置窗口固定大小（无法拉伸或缩放）
    setFixedSize(600, 400);

    // 按钮创建方式一
    QPushButton *btn1 = new QPushButton;

    // show以顶层方式弹出
    // btn->show();

    // 显示到当前窗口。
    btn1->setParent(this);
    // 设置按钮文字，接受QString
    btn1->setText("Hello Qt1");
    // 重置按钮大小
    btn1->resize(100,100);

    // 按钮创建方式二
    QPushButton *btn2 = new QPushButton("Hello Qt2", this);
    // 移动按钮位置
    btn2->move(100, 100);

    // 创建自定义按钮
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setParent(this);
    myBtn->setText("MyPushButton");
    myBtn->move(200, 200);
    myBtn->resize(100,100);

    // 信号槽
    connect(myBtn, &MyPushButton::clicked, this, &MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

