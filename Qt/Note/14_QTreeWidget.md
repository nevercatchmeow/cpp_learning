## QTreeWidget



- 创建树干：

  ```c
  // 树干
  ui->treeWidget->setHeaderLabels(QStringList() << "蘑菇" << "蘑菇简介");
  ```

- 创建树枝

  ```c
  // 树枝
  QTreeWidgetItem * buffMushroom = new QTreeWidgetItem(QStringList() << "增益蘑菇");
  QTreeWidgetItem * debuffMushroom = new QTreeWidgetItem(QStringList() << "减益蘑菇");
  ```

- 树干放入树枝

  ```c
  // 树枝放入树干
  ui->treeWidget->addTopLevelItem(buffMushroom);
  ui->treeWidget->addTopLevelItem(debuffMushroom);
  ```

- 创建树叶

  ```c
  // 树叶
  QTreeWidgetItem * blueMushroom 
      			= new QTreeWidgetItem(QStringList() << "蓝蘑菇" << "守得云开见月明");
  QTreeWidgetItem * blackMushroom 
      			= new QTreeWidgetItem(QStringList() << "黑蘑菇" << "黑魔法导师");
  QTreeWidgetItem * redMushroom 
      			= new QTreeWidgetItem(QStringList() << "红蘑菇" << "还没想好...");
  QTreeWidgetItem * greenMushroom 
      			= new QTreeWidgetItem(QStringList() << "绿蘑菇" << "青青草原");
  ```

- 树叶放入树枝

  ```c
  // 树叶放入树枝
  buffMushroom->addChild(blueMushroom);
  buffMushroom->addChild(blackMushroom);
  debuffMushroom->addChild(redMushroom);
  debuffMushroom->addChild(greenMushroom);
  ```

  

