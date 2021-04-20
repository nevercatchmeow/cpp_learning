#include "mainwindow.h"

#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    // 菜单栏（仅一个）
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    // 创建菜单
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");
    // 创建菜单项
    QAction * newFile = fileMenu->addAction("新建文件");
    QAction * openFile = fileMenu->addAction("打开文件");
    // 添加分割线
    fileMenu->addSeparator();
    QAction * saveFile = fileMenu->addAction("保存文件");


    // 工具栏（可多个）
    QToolBar * toolBar = new QToolBar();
    // 默认停靠在左侧
    addToolBar(Qt::LeftToolBarArea, toolBar);
    // 设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // 设置浮动（不允许浮动）
    toolBar->setFloatable(false);
    // 设置移动（不允许移动）
    toolBar->setMovable(false);
    // 工具栏放入小部件
    toolBar->addAction(newFile);
    // 添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openFile);


    // 状态栏（仅一个）
    QStatusBar * stBar = statusBar();
    setStatusBar(stBar);

    QLabel * label1 = new QLabel("左侧提示信息", this);
    stBar->addWidget(label1);
    QLabel * label2 = new QLabel("右侧提示信息", this);
    stBar->addPermanentWidget(label2);


    // 铆接部件（浮动窗口）
    QDockWidget * dock = new QDockWidget();
    // 默认停靠在上方
    addDockWidget(Qt::TopDockWidgetArea, dock);
    // 只允许左右停靠
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // 核心部件（仅一个）
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);


}

MainWindow::~MainWindow()
{
}

