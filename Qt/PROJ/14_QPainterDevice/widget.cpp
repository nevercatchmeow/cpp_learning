#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QPixmap做绘图设备
#if 0
    QPixmap pix(300, 300);
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150,150), 100, 100);
    pix.save(".\\pix.png");
#endif

    //QImage做绘图设备，不同平台显示效果一样， 对像素访问做优化
#if 0
    QImage img(300, 300, QImage::Format_RGB32);
    img.fill(Qt::white);
    QPainter painter(&img);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    img.save(".\\img.png");
#endif

    // QPicture 记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(150, 150), 100, 100);

    painter.end();
    pic.save(".\\pic.zt");  // 存储以上begin至end之间的命令
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{

    QImage img;
    img.load(":/Image/Luffy.png");
    QPainter painter(this);
#if 0
    // 修改像素点
    for (int i = 100; i < 150; ++i)
    {
        for (int j = 100; j < 150; ++j)
        {
            QRgb value = qRgb(255, 0, 0);
            img.setPixel(i, j , value);
        }
    }
    painter.drawImage(0, 0, img);
#endif

    // 重现QPicture
    QPicture pic;
    pic.load(".\\pic.zt");
    painter.drawPicture(0, 0, pic);
}

