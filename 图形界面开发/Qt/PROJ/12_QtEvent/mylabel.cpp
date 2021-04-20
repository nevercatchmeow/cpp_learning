#include "mylabel.h"

#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

// 鼠标进入事件
void MyLabel::enterEvent(QEvent *)
{
    qDebug() << "鼠标进入...";
}

// 鼠标离开事件
void MyLabel::leaveEvent(QEvent *)
{
    qDebug() << "鼠标离开...";
}

// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    // 触发键：左键
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按下... [%1, %2]").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

// 鼠标释放事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    // 触发键：左键
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标释放... [%1, %2]").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    // 触发键：左键
    if(ev->buttons() & Qt::LeftButton)
    {
        QString str = QString("鼠标移动... [%1, %2]").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

bool MyLabel::event(QEvent *e)
{
    // 拦截鼠标按下事件（不向下分发）
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* ev = static_cast<QMouseEvent*>(e);
        QString str = QString("Event中鼠标按下... [%1, %2]").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        return true;
    }
    else // 其他事件交由父类处理
    {
        return QLabel::event(e);
    }
}
