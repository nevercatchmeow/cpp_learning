#include "mainscene.h"
#include "ui_mainscene.h"

#include "mypushbutton.h"
#include <QtDebug>
#include <QPainter>
#include <QTimer>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    // 主场景基本配置
    this->setWindowTitle("Coin Flip");
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    // 退出
    connect(ui->actionExit, &QAction::triggered, [=](){
        this->close();
    });

    // 创建选择关卡的场景
    chooseScene = new ChooseLevelScene();
    // 开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);
    startBtn->setParent(this);

    // 监听选择关卡场景中的返回按钮发出的自定义信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
        chooseScene->hide();
        this->show();
    });

    connect(startBtn, &QPushButton::clicked, [=](){
        startBtn->zoomDown();
        startBtn->zoomUp();
        qDebug() << "Satrt按钮按下...";

        QTimer::singleShot(200, this, [=](){
            // 隐藏主界面
            this->hide();
            // 显示关卡选择界面
            chooseScene->show();
        });
    });
}

MainScene::~MainScene()
{
    delete ui;
}

// 使用绘图事件绘制背景
void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() >> 1, pix.height() >> 1);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
