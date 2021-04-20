#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "student.h"
#include "teacher.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Teacher *te;
    Student *st;

    void classIsOver();
};
#endif // MAINWINDOW_H
