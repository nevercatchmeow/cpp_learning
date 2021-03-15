#include "mainwindow.h"

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
    void (Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void (Student:: *studentSignal)(QString) = &Student::treat;
    connect(te, teacherSignal, st, studentSignal);
    classIsOver();
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
