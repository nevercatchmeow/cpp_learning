#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击按钮弹出对话框
    connect(ui->pushButton, &QPushButton::clicked, [=]()
    {
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\shinrin\\Desktop\\新建文本文档.txt");
        qDebug() << filePath;
        if(filePath.isEmpty())
        {
            QMessageBox::warning(this, "警告", "文件路径不能为空");
            return;
        }
        else
        {
            // 将文件路径放入lineEdit中
            ui->lineEdit->setText(filePath);
            // 文本编码格式类
            // QTextCodec * codec = QTextCodec::codecForName("gbk");
            // 将文件内容读取到textEdit中
            QFile file(filePath);

            /*
             * 读文件
             */
            // 指定打开方式
            file.open(QIODevice::ReadOnly);
            // 默认支持utf-8格式
            QByteArray array;
            // 全部读取
            // array = file.readAll();
            // 按行全部读取
            while (!file.atEnd())
            {
                array += file.readLine();
            }
             ui->textEdit->setText(array); // utf-8
            // ui->textEdit->setText(codec->toUnicode(array)); // gbk 转 unicode
             file.close();

             /*
              * 写文件
              */
             file.open(QIODevice::Append);
             file.write("\n写文件测试");
             file.close();

             /*
              * 读文件信息
              */
             QFileInfo info(filePath);
             qDebug() << "\n文件后缀：" << info.suffix()
                      << "\n文件大小：" << info.size() // 字节数
                      << "\n文件名称：" << info.fileName()
                      << "\n文件路径：" << info.filePath();
             qDebug() << "创建日期：" << info.birthTime().toString("yyyy-MM-dd hh:mm:ss");
             qDebug() << "最后修改日期：" << info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

