## Scroll Area

滚动条。



## Tool Box

类似于QQ好友分组栏。

- 修改分组名称：对象 => 类 => 选中 Tool Box => CurrentItemText
- 加入新的栏目：对象 => 类 => 右键 Tool Box => 插入页（当前页之前 / 当前页之后） 



## Tab Widget

标签页。

- 修改分组名称：对象 => 类 => 选中 Tab Widget => CurrentTabText
- 加入新的栏目：对象 => 类 => 右键 Tab Widget => 插入页（当前页之前 / 当前页之后） 



## Stacked Widget

依次将 Scroll Area、Tool Box 、Tab Widget 放入 Stacked Widget，默认只显示第一页，需要根据每页的索引绑定三个按钮以进行切换。

```c++
connect(ui->btn_ScrollArea, &QPushButton::clicked, [=](){
    ui->stackedWidget->setCurrentIndex(0);
});

connect(ui->btn_ToolBox, &QPushButton::clicked, [=](){
    ui->stackedWidget->setCurrentIndex(1);
});

connect(ui->btn_TabWidget, &QPushButton::clicked, [=](){
    ui->stackedWidget->setCurrentIndex(2);
});
```



## Combo Box

```c++
// 下拉框
ui->comboBox->addItem("C");
ui->comboBox->addItem("D");
ui->comboBox->addItem("E");
ui->comboBox->addItem("F");

connect(ui->btn_ChooseE, &QPushButton::clicked, [=](){
    // ui->comboBox->setCurrentIndex(2);
    ui->comboBox->setCurrentText("E");
});
```



## QLabel

```c++
// QLabel 显示图片
ui->label_img->setPixmap(QPixmap(":/Image/Frame.jpg"));
// QLabel 显示动画
QMovie *movie = new QMovie(":/Image/mario.gif");
ui->label_movie->setMovie(movie);
movie->start();
```

