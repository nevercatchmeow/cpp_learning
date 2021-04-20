## QListWidget

- 单次添加一行：使用QListWidgetItem，可设置对齐方式。

  ```c
  // QListWidgetItem
  QListWidgetItem * item1 = new QListWidgetItem("人生到处知何似");
  QListWidgetItem * item2 = new QListWidgetItem("应似飞鸿踏雪泥");
  
  // 文本居中
  item1->setTextAlignment(Qt::AlignCenter);
  item2->setTextAlignment(Qt::AlignCenter);
  // 将QListWidgetItem加入QListWidget
  ui->listWidget1->addItem(item1);
  ui->listWidget1->addItem(item2);
  ```

- 单次添加多行：使用 QStringList，无法设置对齐方式。

  ```c
  // QStringList => QList<QString> => list<String>
  // 使用 QStringList 一次添加多行。
  QStringList list;
  list << "人生到处知何似" << "应似飞鸿踏雪泥";
  ui->listWidget2->addItems(list);
  ```



