#include "mypushbutton.h"

#include <QPropertyAnimation>
#include <QDebug>

// MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
// {

// }

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    // QPixmap 加载图标
    QPixmap pix;
    bool ret = pix.load(normalImgPath);
    if(!ret)
    {
        QString str = QString("图片加载失败 %1").arg(normalImgPath);
        qDebug() << str;
        return;
    }
    // 设置图片大小
    this->setFixedSize(pix.width(), pix.height());
    // 设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    // 设置图标
    this->setIcon(pix);
    // 设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));

}

// 下弹
void MyPushButton::zoomDown()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    // 设置动画时间间隔
    animation->setDuration(200);
    // 设置起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    // 设置结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    // 设置弹起效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 动画执行
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

// 上弹
void MyPushButton::zoomUp()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    // 设置动画时间间隔
    animation->setDuration(200);
    // 设置起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    // 设置结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    // 设置弹起效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 动画执行
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

// 重写鼠标按下
void MyPushButton::mousePressEvent(QMouseEvent* event)
{
    if(this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(pressImgPath);
        if(!ret)
        {
            QString str = QString("图片加载失败 %1").arg(pressImgPath);
            qDebug() << str;
            return;
        }
        // 设置图片大小
        this->setFixedSize(pix.width(), pix.height());
        // 设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        // 设置图标
        this->setIcon(pix);
        // 设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    QPushButton::mousePressEvent(event);

}
// 重写鼠标释放
void MyPushButton::mouseReleaseEvent(QMouseEvent* event)
{
    if(this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(normalImgPath);
        if(!ret)
        {
            QString str = QString("图片加载失败 %1").arg(normalImgPath);
            qDebug() << str;
            return;
        }
        // 设置图片大小
        this->setFixedSize(pix.width(), pix.height());
        // 设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        // 设置图标
        this->setIcon(pix);
        // 设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    QPushButton::mouseReleaseEvent(event);
}
