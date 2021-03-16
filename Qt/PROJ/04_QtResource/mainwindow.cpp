#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 为新建菜单栏添加图标
    ui->actionCreatFile->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionOpenFile->setIcon(QIcon(":/Image/LuffyQ.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

