#include "mainwindow.h"

#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // this 放入对象树。
    this->te = new Teacher(this);
    this->st = new Student(this);

    // 连接无参信号与槽。
    // connect(te, &Teacher::hungry, st, &Student::treat);
    // classIsOver();

    // 连接有参信号与槽。
    // void (Teacher:: *teacherSignal1)(QString) = &Teacher::hungry;
    // void (Student:: *studentSlot1)(QString) = &Student::treat;
    // connect(te, teacherSignal1, st, studentSlot1);
    // classIsOver();

    // 创建按钮
    // QPushButton * btn = new QPushButton("下课", this);
    // void (Teacher:: *teacherSignal2)() = &Teacher::hungry;
    // void (Student:: *studentSlot2)() = &Student::treat;

     resize(600,400);
    // 扩展
    // 1.信号连接信号
    // connect(te, teacherSignal2, st, studentSlot2);
    // connect(btn, &QPushButton::clicked, te, teacherSignal2);
    // 2.断开信号与槽
    // disconnect(te, teacherSignal2, st, studentSlot2);
    // 3.一个信号连接多个槽函数
    // connect(btn, &QPushButton::clicked, te, teacherSignal2);
    // connect(btn, &QPushButton::clicked, this, &MainWindow::close);
    // 4.多个信号可绑定同一个槽函数
    // 5.信号与槽函数的参数类型必须一致
    // 6.信号的参数个数可以多于槽函数的参数个数，反之不成立（类型一一对应）

    // 信号与槽（Qt4）
    // connect(te, SIGNAL(hungry(QString)), st, SLOT(treat(QString)));
    // classIsOver();

    // Lambda表达式
    QPushButton * btn2 = new QPushButton("abc", this);
    QPushButton * btn3 = new QPushButton("def", this);
    [=]()
    {
        btn2->setText("cba");
        btn3->move(0, 100);
        btn3->setText("fed");
    }();

    QPushButton *btn4 = new QPushButton("aaa", this);
    btn4->move(100, 0);

    // 常用Lambda应用：[=](){}
    // 当进行信号和槽连接时，控件内部进入锁的状态。
    connect(btn4, &QPushButton::clicked, this,[=](){
        btn4->setText("bbb");
    });

    // mutable示例
    QPushButton * btn5 = new QPushButton("Button1", this);
    QPushButton * btn6 = new QPushButton("Button2", this);
    btn5->move(0, 200);
    btn6->move(0, 300);
    int m = 10;
    connect(btn5, &QPushButton::clicked, this, [m]() mutable{
        m = 20;
        qDebug() << m;
    });
    connect(btn6, &QPushButton::clicked, this, [=]() mutable{
        m = 20;
        qDebug() << m;
    });

    // Lambda返回值
    int num = [=]()->int{
        return 1000;
    }();
    qDebug() << "num = " << num;

    // 点击按钮关闭窗口
    connect(btn6, &QPushButton::clicked, this, [=](){
        this->close();
    });

    connect(btn6, &QPushButton::clicked, this, [=](){
        st->treat("茶树菇炒肉");
    });
}

MainWindow::~MainWindow()
{
}

void MainWindow::classIsOver()
{
    // emit触发自定义信号。
    // emit this->te->hungry();
    emit this->te->hungry("茶树菇炒肉");
}
