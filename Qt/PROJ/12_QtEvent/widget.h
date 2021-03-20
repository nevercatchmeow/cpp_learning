#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void timerEvent(QTimerEvent*);
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;

    int timer_id1;
    int timer_id2;

    bool timerStop = false;

};
#endif // WIDGET_H
