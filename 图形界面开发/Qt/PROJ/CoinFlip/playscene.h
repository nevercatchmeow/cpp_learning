#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "mycoin.h"

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    // explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelIndex);
    int levelIndex;
    // 重写绘图事件
    void paintEvent(QPaintEvent *) override;
    // 记录当前关卡的二维数组
    int gameArray[4][4];
    // 金币按钮数组
    MyCoin * coinBtn[4][4];
    bool isWin;

signals:
    void playSceneBack();
public slots:
};

#endif // PLAYSCENE_H
