## QTableWidget

- 设置列数

  ```c
  // 设置列数
  ui->tableWidget->setColumnCount(3);
  ```

- 设置水平表头

  ```c
  // 设置水平表头
  ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "英雄姓名" << "英雄称号" << "终极技能");
  ```

- 设置行数

  ```c
  // 设置行数
  ui->tableWidget->setRowCount(5);
  ```

- 数据填充

  ```c
  // 数据填充
  QStringList heroName;
  heroName << "盖伦" << "德莱厄斯" << "亚索" << "李青" << "提莫";
  QStringList heroTitle;
  heroTitle << "德玛西亚之力" << "诺克萨斯之手" << "疾风剑豪" << "盲僧" << "迅捷斥候";
  QStringList ultimateSkill;
  ultimateSkill << "德玛西亚正义" << "诺克萨斯断头台" << "狂风绝息斩" << "神龙摆尾" << "种蘑菇";
  
  for (int row = 0; row < 5; row ++) {
      int col = 0;
      ui->tableWidget->setItem(row, col++, new QTableWidgetItem(heroName[row]));
      ui->tableWidget->setItem(row, col++, new QTableWidgetItem(heroTitle[row]));
      ui->tableWidget->setItem(row, col++, new QTableWidgetItem(ultimateSkill[row]));
  }
  ```

  