#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    // 重写绘图事件
    void paintEvent(QPaintEvent *event) override;
    PlayScene* playScene;

signals:
    // 点击返回按钮后，抛出自定义信号（无需实现）
    void chooseSceneBack();

public slots:
};

#endif // CHOOSELEVELSCENE_H
