#include "playscene.h"
#include "mypushbutton.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QtDebug>
#include <QTimer>
#include <QLabel>
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelIndex)
{
    // 记录用户选择的具体关卡
    this->levelIndex = levelIndex;
    qDebug() << "用户选择的是 " << this->levelIndex << "关";

    // 设置标题
    this->setWindowTitle("翻金币");
    // 窗口大小
    this->setFixedSize(320,588);
    // 设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    // 菜单栏
    QMenuBar * bar = menuBar();
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quickMenu = startMenu->addAction("退出");
    connect(quickMenu, &QAction::triggered, [=](){
        this->close();
    });

    // 返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &MyPushButton::clicked, [=](){
        // 延时发送返回信号
        QTimer::singleShot(200, this, [=](){
            emit this->playSceneBack();
        });
    });

    // 创建具体用户选择的关卡标签
    QLabel * label = new QLabel();
    label->setParent(this);

    QString str = QString("level: %1").arg(this->levelIndex);
    label->setText(str);
    // 设置字体和字号
    QFont font;
    font.setFamily("Courier");
    font.setPointSize(16);
    font.setBold(2);
    label->setFont(font);

    // 设置大小和位置
    label->setGeometry(QRect(30, this->height() - 50, 120, 50));

    // 创建金币背景图片
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            // QLabel显示图片
            QLabel* label = new QLabel();
            QPixmap pix;
            pix.load(":/res/BoardNode.png");
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57 + i*pix.width(), 200 + j*pix.height());
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *event)
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
