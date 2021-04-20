#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString imgPath);
    void changeFlag();  // 改变标志，执行翻转效果
    void mousePressEvent(QMouseEvent *event);

    // x坐标
    int posX;
    // y坐标
    int posY;
    // 正反标志
    bool flag;

    QTimer *timer1; // 正面翻反面
    QTimer *timer2; // 反面翻正面
    int min = 1;
    int max = 8;

    bool isAnimation = false; // 当前是否正在翻转标志
    bool isWin = false; // 是否胜利

signals:

public slots:
};

#endif // MYCOIN_H
