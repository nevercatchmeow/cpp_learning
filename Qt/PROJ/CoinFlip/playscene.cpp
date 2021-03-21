#include "playscene.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QtDebug>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSound>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelIndex)
{
    // 记录用户选择的具体关卡
    this->levelIndex = levelIndex;
    qDebug() << "用户选择的是 " << this->levelIndex << "关";

    // 设置标题
    this->setWindowTitle("Coin Flip");
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

    // 音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav");
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav");
    QSound *winSound = new QSound(":/res/LevelWinSound.wav");

    // 返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &MyPushButton::clicked, [=](){
        backSound->play();
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

    // 初始化二维数组
    dataConfig config;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    // 胜利图片
    QLabel * winLabel = new QLabel();
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width()-tmpPix.width())*0.5, -tmpPix.height());

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

            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str = ":/res/Coin0001.png";
            }
            else
            {
                str = ":/res/Coin0008.png";
            }

            // 创建金币
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i*pix.width(), 204 + j*pix.height());
            // 金币属性
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];
            // 金币放入二维数组中
            coinBtn[i][j] = coin;
            // 监听点击按钮信号
            connect(coin, &MyCoin::clicked, [=](){
                flipSound->play();
                // 屏蔽所有按钮
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        coinBtn[i][j]->isWin = true;
                    }
                }
                coin->changeFlag();
                // 同步二维数组
                this->gameArray[i][j] = this->gameArray[i][j] == 1 ? 0 : 1;
                // 翻转周围金币
                // 检测右侧金币是否可翻转
                if(coin->posX + 1 <= 3)
                {
                    coinBtn[coin->posX+1][coin->posY]->changeFlag();
                    this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 1 ? 0 : 1;
                }
                // 检测左侧金币是否可翻转
                if(coin->posX - 1 >= 0)
                {
                    coinBtn[coin->posX-1][coin->posY]->changeFlag();
                    this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 1 ? 0 : 1;
                }
                // 检测上侧金币是否可翻转
                if(coin->posY - 1 >= 0)
                {
                    coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                    this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 1 ? 0 : 1;
                }
                // 检测下侧金币是否可翻转
                if(coin->posY + 1 <= 3)
                {
                    coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                    this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 1 ? 0 : 1;
                }
                // 屏蔽所有按钮
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        coinBtn[i][j]->isWin = false;
                    }
                }
                this->isWin = true;
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        if(coinBtn[i][j]->flag == false)
                        {
                            this->isWin = false;
                            break;
                        }
                    }
                }
                if(isWin)
                {
                    qDebug() << "胜利！";
                    winSound->play();
                    for (int i = 0; i < 4; ++i)
                    {
                        for (int j = 0; j < 4; ++j)
                        {
                            coinBtn[i][j]->isWin = true;
                        }
                    }
                    QPropertyAnimation *animation = new QPropertyAnimation(winLabel, "geometry");
                    animation->setDuration(1000);
                    animation->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                    animation->setEndValue(QRect(winLabel->x(), winLabel->y()+174, winLabel->width(), winLabel->height()));
                    animation->setEasingCurve(QEasingCurve::OutBounce);
                    animation->start(QAbstractAnimation::DeleteWhenStopped);
                }
            });
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
