#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标进入事件
    void enterEvent(QEvent *) override;
    // 鼠标离开事件
    void leaveEvent(QEvent *) override;
    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *ev) override;
    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev) override;
    // 鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev) override;

    bool event(QEvent*) override;

signals:

public slots:
};

#endif // MYLABEL_H
