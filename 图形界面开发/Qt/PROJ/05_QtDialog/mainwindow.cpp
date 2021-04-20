#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 对话框分类：
    //   模态对话框：不能对其他窗口进行操作（阻塞在对话框）。
    //   非模态对话框：可以对其他窗口进行操作。

    // 模态对话框：点击创建，新建对话框
    connect(ui->actionCreatFile, &QAction::triggered, this, [=](){
        // 模态对话框：点击创建，新建对话框
//        QDialog *dlg = new QDialog(this);
//        dlg->resize(400, 150);
//        dlg->exec();
//        // 关闭时释放，避免内存泄露。
//        dlg->setAttribute(Qt::WA_DeleteOnClose);


        // 非模态对话框：点击创建，新建对话框
//        QDialog *dlg = new QDialog(this);
//        dlg->resize(400, 150);
//        dlg->show();
//        // 关闭时释放，避免内存泄露。
//        dlg->setAttribute(Qt::WA_DeleteOnClose);


        // 错误提示对话框
//        QMessageBox::critical(this, "Error", "some thing happened...");
        // 信息提示对话框
//        QMessageBox::information(this, "Info", "information..");
        // 询问提示对话框
        // QMessageBox::question(this, "Question", "question...", QMessageBox::Save | QMessageBox::Cancel);
        // 参数：对象树、 标题、提示信息、按键类型、默认关联回车键
//        if(QMessageBox::Save == QMessageBox::question(this, "Question", "question...", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
//        {
//            qDebug() << "Save";
//        }
        // 警告提示对话框
//        QMessageBox::warning(this, "Warning", "warning..");

        // 颜色选择对话框
//        QColor color = QColorDialog::getColor(Qt::red);
//        qDebug() << color.red() << color.green() << color.blue();

        // 文件选择对话框
//        QString filename = QFileDialog::getOpenFileName(this, "Open file", "C:\\Users\\shinrin\\Documents", "(*.jpg)");
//        qDebug() << filename;

        // 字体选择对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("楷体", 36));
        qDebug() << "字体" << font.family() << "字号" << font.pointSize() << "是否加粗" << font.bold() << "是否倾斜" << font.italic();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

