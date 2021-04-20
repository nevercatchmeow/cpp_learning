#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 开启定时器 / 使用timerID()区分定时器
    timer_id1 = startTimer(1000); // 1000ms
    timer_id2 = startTimer(2000); // 2000ms

    // 创建定时器对象
    QTimer* timer = new QTimer(this);
    timer->start(500); // 每500ms产生一个信号。
    connect(timer, &QTimer::timeout, [=](){
        // 每隔0.5秒让label_timer_3的数字+1
        static int num;
        ui->label_timer_3->setText(QString::number(num++));
    });
    // 点击按钮，定时器停止计时
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        if(!timerStop)
        {
            timer->stop();
            this->timerStop = true;
            ui->pushButton->setText(QString("CONTINUE"));
        }
        else
        {
            timer->start(500);
            this->timerStop = false;
            ui->pushButton->setText(QString("STOP"));
        }
    });

    // 为label添加事件过滤器，做高级拦截操作。
    ui->label_mouse->installEventFilter(this);
}

// 重写过滤器事件
bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->label_mouse)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* ev = static_cast<QMouseEvent *>(e);
            QString str = QString(" 事件过滤器 鼠标按下... [%1, %2]").arg(ev->x()).arg(ev->y());
            qDebug() << str;
            return true;
        }
    }
    return QWidget::eventFilter(obj, e);
}

Widget::~Widget()
{
    delete ui;
}

// 添加定时器事件
void Widget::timerEvent(QTimerEvent* e)
{
    // 每隔1秒让label_timer_1的数字+1
    if(e->timerId() == timer_id1)
    {
        static int num_1 = 1;
        ui->label_timer_1->setText(QString::number(num_1++));
    }

    if(e->timerId() == timer_id2)
    {
        // 每隔2秒让label_timer_2的数字+1
        static int num_2 = 1;
        ui->label_timer_2->setText(QString::number(num_2++));
    }
}
