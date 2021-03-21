#include "chooselevelscene.h"
#include "mypushbutton.h"

#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    // 菜单栏
    QMenuBar * bar = menuBar();
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quickMenu = startMenu->addAction("退出");
    connect(quickMenu, &QAction::triggered, [=](){
        this->close();
    });

    // 设置标题
    this->setWindowTitle("选择关卡");
    // 窗口大小
    this->setFixedSize(320,588);
    // 设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    // 返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &QPushButton::clicked, [=](){
        // 延时发送返回信号
        QTimer::singleShot(200, this, [=](){
            emit this->chooseSceneBack();
            this->hide();
        });
    });

    // 创建20个选择关卡的小按钮
    for (int i = 0; i < 20; ++i)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + (i % 4) * 70, 130 + (i / 4) * 70);
        connect(menuBtn, &MyPushButton::clicked, [=](){
            this->hide();
            playScene = new PlayScene(i+1);
            this->playScene->show();
            // 监听游戏场景中的返回按钮发出的信号
            connect(this->playScene, &PlayScene::playSceneBack, [=](){
                this->playScene->close();
                delete this->playScene;
                this->playScene = nullptr;
                this->show();
            });
        });
        // 创建显示具体关卡号的label
        QLabel * label = new QLabel();
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->move(25 + (i % 4) * 70, 130 + (i / 4) * 70);
        QFont font;
        font.setFamily("Courier");
        font.setPointSize(8);
        font.setBold(2);
        label->setFont(font);
        // 设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);


    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    // 加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);


}
