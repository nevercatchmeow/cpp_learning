#include "mycoin.h"

#include <QDebug>

//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{
//}

MyCoin::MyCoin(QString imgPath)
{
    QPixmap pix;
    bool ret = pix.load(imgPath);
    if(!ret)
    {
        qDebug() << "图片加载失败" << imgPath;
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    // 初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    // 监听定时器timeout
    // 金币翻银币
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug() << "图片加载失败" << imgPath;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if(this->min > this->max)
        {
            this->min = 1;
            timer1->stop();
            this->isAnimation = false;
        }
    });
    // 银币翻金币
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->max--);
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug() << "图片加载失败" << imgPath;
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        if(this->max < this->min)
        {
            this->max = 8;
            timer2->stop();
            this->isAnimation = false;
        }
    });
}

// 改变金币状态
void MyCoin::changeFlag()
{
    if(this->flag)  // 金币改银币
    {
        // 启动金币翻银币的定时器
        timer1->start(30);
        this->isAnimation = true;
        this->flag = false;
    }
    else    // 银币改金币
    {
        timer2->start(30);
        this->isAnimation = false;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *event)
{
    if(this->isAnimation || this->isWin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(event);
    }
}
