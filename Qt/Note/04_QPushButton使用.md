## QPushButton

头文件：

```c++
#include <QPushButton>
```

使用：

```c++
// 重置窗口大小
// resize(600, 400);

// 设置窗口标题
setWindowTitle("First Window");

// 设置窗口固定大小（无法拉伸或缩放）
setFixedSize(600, 400);

//---------------------------------------------------------------------------------------

// 按钮创建方式一
QPushButton *btn1 = new QPushButton;

// show以顶层方式弹出
// btn->show();

// 显示到当前窗口。
btn1->setParent(this);

// 设置按钮文字，接受QString
btn1->setText("Hello Qt1");

// 重置按钮大小
btn1->resize(100,100);

// 按钮创建方式二
QPushButton *btn2 = new QPushButton("Hello Qt2", this);

// 移动按钮位置
btn2->move(100, 100);
```

