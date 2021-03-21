#ifndef PLAYSCENE_H
#define PLAYSCENE_H

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
signals:
    void playSceneBack();
public slots:
};

#endif // PLAYSCENE_H
