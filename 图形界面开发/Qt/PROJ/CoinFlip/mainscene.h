#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    // 使用绘图事件绘制背景
    void paintEvent(QPaintEvent *event) override;
    // 维护选择关卡场景的指针
    ChooseLevelScene * chooseScene;

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
