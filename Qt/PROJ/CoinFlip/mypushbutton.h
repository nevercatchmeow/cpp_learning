#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QWidget>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyPushButton(QWidget *parent = nullptr);

    QString normalImgPath;
    QString pressImgPath;
    // normalImg：正常显示的图片
    // pressImg：按下后显示的图片
    MyPushButton(QString normalImg, QString pressImg = "");

    // 下弹
    void zoomDown();
    // 上弹
    void zoomUp();

    // 重写鼠标按下
    void mousePressEvent(QMouseEvent* event) override;
    // 重写鼠标释放
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
