#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

    // 自定义信号在signals下。
signals:
    // 返回值类型：void
    // 只声明，不实现。
    // 可含参，可重载。
    void hungry();
    void hungry(QString foodName);

public slots:
};

#endif // TEACHER_H
