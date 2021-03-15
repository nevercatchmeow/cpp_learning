#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

    // 自定义槽函数，public slot下。
public slots:
    // 返回值类型：void
    // 需要声明与实现。
    // 可含参，可重载。
    void treat();

    void treat(QString foodName);
};

#endif // STUDENT_H
