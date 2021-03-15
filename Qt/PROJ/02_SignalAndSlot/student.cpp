#include "student.h"

#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "Teacher and Student eat eat ...";
}

void Student::treat(QString foodName)
{
    // QString转char *：
    //  1. 通过.toUtf8() 转为QByteArray类型。
    //  2. 通过.data() 转为QByteArray类型。
    qDebug() << "Teacher and Student eat eat ..." << foodName.toUtf8().data();
}
