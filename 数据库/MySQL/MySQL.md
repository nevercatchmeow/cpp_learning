# 一、数据库选择

## 数据库比较

| 数据库  | 特点                                                         | 应用场景                           |
| ------- | ------------------------------------------------------------ | ---------------------------------- |
| Oracle  | 大型关系型数据库（收费）：存储大量数据，可进行海量数据分析，多用于银行或金融机构。 | 高安全性、海量数据，高成本。       |
| MySQL   | 轻量级关系型数据库（免费）：开源、跨平台（使用灵活）。       | 快速查询、一般情况下的高并发访问。 |
| Redis   | 缓存数据库（非关系型数据库）：对于数据读写较快，多用于高并发场景，配合关系型数据库作高速缓存，降低磁盘IO。 | 高并发、数据读写。                 |
| MongoDB |                                                              |                                    |
| 其他... |                                                              |                                    |

# 二、MySQL安装（Windows）

## 2.1 下载

下载地址：https://dev.mysql.com/downloads/windows/installer/8.0.html 

## 2.2 安装

（以8.0.23版本为例）

### 2.2.1 Choosing a Setup Type

选择安装类型，以下二选一

- Developer Default（安装开发者默认功能，C盘）

- Custom（安装自定义功能，点击右下角Advanced Options可选择安装目录、数据目录）

  ```bash
  # Install Directory
  E:\App\MySQL\MySQL Server 8.0
  # Data Directory
  E:\AppData\MySQL\MySQL Server 8.0
  ```

### 2.2.2 Check Requirements

检查环境，点击Execute安装所缺的依赖环境。

### 2.2.3 Installation：

点击Execute执行安装。

### 2.2.4 Product Configuration

对MySQL进行配置。

- Type and Networking：网络端口设置（默认）

- Authentication Method：Using Strong Password...（选择授权方法：强密码）

- Account and Roles：

  - 设置Root密码

    ```
    lc714462439
    ```

  - 添加MySQL用户

    ```
    User Name: kevin
    Host: localhost
    Role: DB Admin
    User Password: lc714462439
    ```

- Windows Service：配置Windows服务（默认）

- MySQL Router Configuration：设置路由（默认）

- Connect to Server：测试（输入Root密码）

- Apply Configuration：Execute（配置生效）

### 2.2.5 Installation Complete

点击Finish以结束安装。

## 2.3 启动服务

### 2.3.1 图形化界面启动

计算机 => 管理 => 服务和应用程序 => 服务 => MySQL80 => 启动 / 停止 / 自动

或

开始 => 控制面板 => 管理工具 => 服务 => MySQL80 => 启动 / 停止 / 自动

### 2.3.2 命令行启动

查看Windows已启动的服务

```powershell
net start
```

关闭MySQL80服务（管理员权限运行PowerShell）

```powershell
net stop MySQL80
```

开启MySQL80服务（管理员权限运行PowerShell）

```powershell
net start MySQL80
```

## 2.4 配置环境变量

### 2.4.1 配置

桌面 => 此电脑 => 右键选择属性 => 高级系统设置 => 环境变量

```
Path变量新建以下值：
	E:\App\MySQL\MySQL Server 8.0\bin
```

### 2.4.2 测试

登录数据库

```powershell
➜ mysql -h 127.0.0.1 -uroot -plc714462439
```

显示数据库

```powershell
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sakila             |
| sys                |
| world              |
+--------------------+
6 rows in set (0.00 sec)
```

退出

```powershell
mysql> quit
Bye
```

# 三、MySQL安装（Ubuntu）

待补充。

# 四、数据库操作

## 4.1 关系模型

关系型数据库建立在关系模型上，关系模型本质是若干个存储数据的二维表。

### 记录

表的每一行称为记录（Record）：即逻辑意义上的数据。

### 字段

表的每一列称为字段（Column）：同一个表的每一行记录拥有相同的若干字段。

字段定义了数据类型（整型、浮点型、字符串、日期等），以及是否为NULL。NULL表示字段数据不存在，通常情况下应避免字段被允许为NULL，如此可以简化查询条件、加快查询速度、利于应用程序读取数据（无需判断）。

### 表与表之间的关系

一对多：一个班级有多个学生。

多对一：多个学生属于一个班级。

一对一：一个班级配一名班主任。

## 4.2 数据库的操作

### 4.2.1 创建数据库

在数据库系统中划分一块空间，用来存储相应的数据。

数据库命名规范：字母（不区分大小）+ 数字 + 下划线'_'，多个单词使用下划线分隔。

语法：```CREATE DATABASE database_name; ```

```powershell
# 启动MySQL80服务
net start MySQL80
# 登录数据库
➜ mysql -h 127.0.0.1 -uroot -plc714462439
# 创建数据库
mysql> CREATE DATABASE school;
Query OK, 1 row affected (0.01 sec)
```

### 4.2.2 查看数据库

语法：```SHOW DATABASES; ```

```powershell
# 显示已存在的数据库（包含已创建的school库）
mysql> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sakila             |
| school             |
| sys                |
| world              |
+--------------------+
7 rows in set (0.00 sec)
```

### 4.2.3 选择数据库

语法：```USE database_name;```

```powershell
mysql> USE school; 
Database changed
```

### 4.2.4 删除数据库

语法：```DROP DATABASE database_name;```

```powershell
mysql> DROP DATABASE school;
Query OK, 0 rows affected (0.03 sec)
```

# 五、数据表操作

创建班级表：

```mysql
#创建数据库school
mysql> create database school;   
#选择数据库school 
mysql> use school;  
#创建表class
mysql> create table class(class_id int, class_name varchar(128), class_teacher varchar(64));        
#往表中插入101班记录
mysql> insert into class values (101, '六年级一班', '吴老师');  
#往表中插入102班记录
mysql>insert into class values (102, '六年级二班', '徐老师');  
#查询表class 中的全部记录
mysql>select * from class;
#查询表class 中calss_id为101的记录
mysql>select * from class where class_id=101;  
```

## 5.1 创建数据表

语法：```CREATE TABLE <表名> ([表定义选项])[表选项][分区选项];```

其中，表定义选项的格式为（<列名1> <类型1>, ..., <列名n> <类型n>）。

例：

```mysql
mysql> use school;  
#创建表class，其中class_id作为主键，class_name不允许为空，class_teacher唯一
mysql> create table class(class_id int PRIMARY KEY, class_name varchar(128) NOT NULL, class_teacher varchar(64) UNIQUE);  
```

表名可指定为 db_name.table_name，以便在特定的数据库中创建表（要求指定的数据库必须存在），若在当前数据库中创建，则自动忽略db_name。

```mysql
#在数据库school中创建表class，数据库school必须存在且当前未选择数据库
mysql> create table school.class(class_id int PRIMARY KEY, class_name varchar(128) NOT NULL, class_teacher varchar(64) UNIQUE);
```

### 5.1.1 列名定义

命名规则：

- 字母+数字+下划线。
- 小写命名，避免出现大写。
- 禁止使用数据库关键字。
- 列名不应重复表的名称。
- 字段使用完整名称。

### 5.1.2 列的类型定义

#### 5.1.2.1 整型类型

##### 整型类型分类

标准SQL支持INTEGER和SMALLINT两种整型类型，MySQL扩展支持TINYINT、MEDIUMINT和BIGINT。

比较如下表：

| 整型类型  | 字节 | 无符号数的取值范围     | 有符号数的取值范围                       |
| --------- | ---- | ---------------------- | ---------------------------------------- |
| TINYINT   | 1    | 0~255                  | -128~127                                 |
| SMALLINT  | 2    | 0~65535                | -32768~32767                             |
| MEDIUMINT | 3    | 0~16777215             | -8388608~8388607                         |
| INT       | 4    | 0~4294967295           | -2147483648~2147483647                   |
| INTEGER   | 4    | 0~4294967295           | -2147483648~2147483647                   |
| BIGINT    | 8    | 0~18446744073709551615 | -9223372036854775808~9223372036854775807 |

##### 整型类型的附带属性

- 类型后的小括号：指定显示宽度，不指定时默认为tinyint(3)、 smallint(5)、 mediumint(8)、 int(11) 和 bigint(20)，常配合zerofill使用（位数不足时用0填充）。

  ```mysql
  mysql> use school;
  mysql> create table class(class_id integer(5) zerofill, class_name varchar(128), class_teacher varchar(64) );
  ```

- UNSIGNED（无符号）：保存非负数和较大的上限值时使用此项，若列指定为zerofill，则自动添加该属性。

  ```mysql
  mysql> use school;
  mysql> create table class(id integer unsigned , name varchar(128), teacher varchar(64) );
  -- zerofill附带unsigned属性。
  mysql> create table class(id integer zerofill , name varchar(128), teacher varchar(64) );
  ```

- AUTO_INCREMENT（自增属性）：需要产生唯一标识或顺序值时使用此项，只作用于整型，从1开始每行加1；一个表只允许有一个AUTO_INCREMENT列，且该列应同时定义为 PRIMARYKEY 或 UNIQUE键。

  ```mysql
  mysql> use school;
  mysql> create table class8(id integer auto_increment PRIMARY KEY , name varchar(128), teacher varchar(64) );
  mysql> create table class9(id integer auto_increment UNIQUE , name varchar(128), teacher varchar(64) );
  ```

#### 5.1.2.2 浮点类型和定点数类型

数据表中用浮点数类型和定点数类型来表示小数：浮点数类型包括单精度浮点数（FLOAT型）和双精度浮点数（DOUBLE型），定点数类型为DECIMAL型。

比较如下表：

| 类型                   | 字节 | 负数取值范围                                        | 非负数取值范围                                       |
| ---------------------- | ---- | --------------------------------------------------- | ---------------------------------------------------- |
| FLOAT                  | 4    | -3.402823466E+38 ~ -1.175494351E-38                 | 0和1.175494351E-38 ~ 3.402823466E+38                 |
| DOUBLE                 | 8    | -1.7976931348623157E+308 ~ -2.2250738585072014E-308 | 0和2.2250738585072014E-308 ~ 1.7976931348623157E+308 |
| DECIMAL(M,D)或DEC(M,D) | M+2  | 同DOUBLE型                                          | 同DOUBLE型                                           |

MySQL浮点型和定点小可用名称类型+(M,D)表示，M表示该值得总共长度，D表示小数点后的长度，M和D称为精度和标度，如float(7,4)可显示为-999.9999，MySQL在保存值时会进行四舍五入，如插入999.00009，则结果为999.0001。对于DECIMAL，M是最大位数（精度），范围是1~65，不指定时默认为10，D是小数点右边的位数（小数位），范围是0~30，但不能大于M，不指定时默认为0。

> FLOAT和DOUBLE在不指定精度时，均按照实际精度显示；而DECIMAL在不指定精度时，默认整数为10，小数为0，即(10,0)。在存储小数且有精度要求时使用DECIMAL。

#### 5.1.2.3 日期和时间类型

YEAR类型表示年，DATE类型表示日期，TIME类型表示时间；DATETIME和TIMESTAMP表示日期和时间。

比较如下表：

| 类型      | 字节 | 取值范围                               | 零值                |
| --------- | ---- | -------------------------------------- | ------------------- |
| YEAR      | 1    | 1901~2155                              | 0000                |
| DATE      | 4    | 1000-01~9999-12-31                     | 0000-00-00          |
| TIME      | 3    | -838:59:59~838:59:59                   | 000:00:00           |
| DATETIME  | 8    | 1000-01 00:00:00 ~ 9999-12-21 23:59:59 | 0000-00-00 00:00:00 |
| TIMESTAMP | 4    | 19700101000000 ~ 2038011931407         | 00000000000000      |

插入日期时间时，日期年月日和时间时分秒可使用“:-_/“中的任意字符来分隔，单独插入时间会报错。

```mysql
mysql> use test;

#创建表dt_example
mysql> create table date_example (e_date date, e_datetime datetime, e_timestamp timestamp, e_time time, e_year year); 
 
mysql> insert into date_example values('2020-5-9', '2020-5-9 15:01:00', '2020-05-09 15:01:00', '15:56:01', 2011);
#效果同上
mysql> insert into date_example values('2020_5/9', '2020:5-9 15/01-00', '2020:05/09 15-01_00',  '15:56:01', '2011');   
```

##### 常用的时间函数

- NOW()： 获得当前的DATETIME，可直接插入DATETIME 和TIMESTAMP类型中。
- CURDATE()：获取当前DATE，可直接插入DATE类型中。
- YEAR()：获取参数给定时间串中的年份，可直接插入YEAR类型中。
- TIME()：获取参数给定时间串中的时分秒，可直接插入TIME 类型中。
- MONTH() 、DAY()、HOUR()、MINUTE()、SECOND() 获取参数给定时间串中的月、日、时、分、秒值。

```mysql
mysql> use test;
mysql> insert into date_example values(CURDATE(), NOW(), NOW(), time(NOW()), YEAR(NOW()) );
```

#### 5.1.2.4 字符串类型

##### 01 CHAR类型和VARCHAR类型

CHAR类型和VARCHAR类型都在创建表时指定了最大长度，其基本形式为：字符串类型(M)，M参数指定了该字符串的最大长度。CHAR类型长度固定，在创建表时指定，可为0~255的任意值，存储时使用空格填充。VARCHAR长度可变，在创建时指定最大长度，可为0~65535之间的任意值，指定后，其长度在0到最大值之间，实际占用空间为字符串的实际长度加1或2，有效节约系统空间。

示例如下：

```mysql
mysql> use test;
#创建数据库表
mysql> create table char_example(e_char char(5), v_char varchar(5)); 
#正常插入数据
mysql> insert into char_example values('12345','12345');  
#char类型会屏蔽后面隐藏的空格，varchar不会
mysql> insert into char_example values('1 2  ','1 2  ');   
#让char后面屏蔽的空格原型毕露 
mysql>select concat('(',e_char, ')'), concat('(',v_char, ')')  from char_example ; 
```

***使用建议：***

	1. char使用指定空间，varchar根据数据来定空间。
 	2. char查询效率高于varchar（varchar通过记录数来计算）。
 	3. 数据为指定长度时使用char，数据长度未知时用varchar。
 	4. 数据长度超过255且小于等于65535时，使用varchar。
 	5. 若需保留字符串尾部空格，使用varchar。

##### 02 TEXT类型

TEXT类型是一种特殊的字符串类型，包括TINYTEXT、TEXT、MEDIUMTEXT和LONGTEXT。

比较如下表：

| 类型       | 允许长度         |
| ---------- | ---------------- |
| TINYTEXT   | 0~255字节        |
| TEXT       | 0~65535字节      |
| MEDIUMTEXT | 0~16772150字节   |
| LONGTEXT   | 0~4294967295字节 |

以上各类型区别在于允许的长度和存储空间不同，使用时无需指定长度，允许的长度指字节数而非字符个数。

示例如下：

```mysql
#选择数据库test 
mysql> use test;   
#创建数据库表，e_text 可存储255个字节，v_char可存储255个字符   
mysql> create table text_example(e_text tinytext, v_char varchar(255)); 
#插入失败，utfmb4 用3个字节表示一个中文汉字，超出tinytext保存范围
mysql> insert into char_example values(90个中文字符,90个中文字符);  
#插入成功
mysql> insert into char_example values(80个中文字符,100个中文字符);  
```

***使用建议：***

1. char类型长度固定，每条数据占用等长字节空间，适用于存储身份证号码、手机号码等，超过255字节的使用varchar 或 text。
2. 属性最大长度未知时使用text。
3. 查询速度：char > varchar > text。

示例：

```mysql
mysql> use test;   #选择数据库test 
mysql> create table userinfo (
    id int(11) unsigned NOT NULL PRIMARY KEY AUTO_INCREMENT COMMENT '主键',
    name varchar(64) DEFAULT NULL COMMENT '姓名',
    mobile char(11) DEFAULT NULL COMMENT '手机号码',
    address varchar(128) DEFAULT NULL COMMENT '居住地址',
    description text DEFAULT NULL COMMENT '个人简介-不知道具体的范围，不常更新用text',
    sex char(1) DEFAULT NULL COMMENT '性别 - 男或女',
    age tinyint unsigned DEFAULT 0 COMMENT '年龄',
    idno char(18) DEFAULT NULL COMMENT '身份证号码'
);
```

##### 03 ENUM和SET类型

ENUM类型又称为枚举类型。在创建表时，ENUM类型的取值范围以列表的形式指定，取值列表最多为65535个值，若数据值列表在255以内，使用一个字节保存；若数据值列表在255~65535范围，采用两个字节保存。列表中每个值有单独编号，MySQL存储时存入该编号（而非列表值），默认编号从1开始。

示例：

```mysql
#选择数据库test 
mysql> use test;   
#创建表 
mysql> create table enum_example (e_enum enum('男','女','保密') ); 
#插入记录,必须是enum 选项中的值
mysql> insert into enum_example values('男');
#插入记录可以用数值表示
mysql> insert into enum_example values(1);  
#查询enum 选项对应的整数值（编号）
mysql>select e_enum + 0  from enum_example; 
```

> 如果ENUM加上NOT NULL属性，则默认值为取值列表的第一个元素，否则允许插入NULL，且默认值为NULL。

SET类型取值范围在创建表时以列表形式指定，SET类型的值可取列表中一个元素或1多个元素的组合，取多个元素时，不同元素用逗号分隔；SET类型的值最多只能取由64个元素构成的组合。

示例：

```mysql
#选择数据库test 
mysql> use test;  
#创建表 
mysql> create table set_example (interest set('足球','追剧','篮球') ); 
#插入记录,必须是set 选项中的值
mysql> insert into set_example values( '足球,追剧' ); 
#插入相应位效果等同，6 => 0110 选择2,3
mysql> insert into set_example values(6);  
#以整数的方式查询
mysql>select interest+0 from set_example;  
```

##### 04 二进制类型

二进制类型与文本类型的区别

> 二进制类型存储原始的二进制数据（如图片，视频，exe文件等），而文本类型（TEXT）用来存储字符字符串（如由英文字符、中文字符或其它语言字符组成的字符串）。 二进制类型没有字符集，并且排序和比较基于列值字节的数值，而TEXT类型有字符集，并且根据字符集的校对规则对值进行排序和比较。

二进制类型是存储二进制数据的数据类型，包括BINARY、VARBINARY、BIT、TINYBLOB、BLOB、MEDIUMBLOB和LONGBLOB。

比较如下表：

| 类型         | 取值范围                                             |
| ------------ | ---------------------------------------------------- |
| BINARY(M)    | 字节数为M，允许长度0~M的定长二进制字符串             |
| VARBINARY(M) | 允许长度为0~M的变长二进制字符串，字节数为值的长度加1 |
| BIT(M)       | M为二进制数据，M最大值64                             |
| TINYBLOB     | 可变长二进制数据，最多 255 个字节                    |
| BLOB         | 可变长二进制数据，最多 2^16 - 1 个字节               |
| MEDIUMBLOB   | 可变长二进制数据，最多 2^24 - 1 个字节               |
| LONGBLOB     | 可变长二进制数据，最多 2^32 - 1 个字节               |

BINARY(M)长度固定，创建表时指定长度为M，不足最大长度的空间由'\0'补全。

VARBINARY(M)长度可变，创建表时指定其最大长度为M，实际长度为0~M。

```mysql
#选择数据库test 
mysql> use test;  
#创建表 
mysql> create table bin_example(e_bin  binary(5),e_varbin varbinary(5)); 
#插入记录,可以是普通字符串
mysql> insert into bin_example values( 'ab','ab'); 
#插入记录,可以是二进制，与上例等同
mysql> insert into bin_example values( b'0110000101100010',b'0110000101100010'); 
#以十六进制的方式显示 
mysql> select * from bin_example ;  
```

BIT(M)，M指定该二进制数最大长度为M，M最大值为64；如BIT(4)，长度为4，可插入的数据为0~15。

```mysql
#选择数据库test 
mysql> use test;   
#创建表 
mysql> create table bit_example (b bit(8) ); 
#插入记录,可以是二进制位
mysql> insert into bit_example values( b'10110111' ); 
#插入记录,可以是字符，但不能超出字节长度
mysql> insert into bit_example values( 'a' ); 
#以二进制的方式显示字段值 
mysql> select bin(b) from bit_example ;  
```

> 插入数据时，使用 b'位串' 的方式插入相应值。
>
> 查询时，使用 bin()、oct()、hex()函数 将字段的值转为相应的二进制、八进制或十六进制。

TINYBLOB、BLOB、MEDIUMBLOB以及LONGBLOB类型无需指定长度，允许的长度即为实际存储的字节数，不考虑字符编码。

***使用建议：***

1. binary长度固定， 即每条数据占用等长字节空间；保存长度不超过255字节的二进制数据。
2. varbinary长度可变，可以设置最大长度M（M <= 65535）；适合用在长度可变的二进制数据。
3. blob不设置长度，当属性的最大长度未知时，适合用blob。
4. 查询速度：binary > varbinary > blob。

### 5.1.3 列的完整性约束

完整性约束条件是对字段进行限制，要求用户对该属性进行的操作符合特定的要求。如果不满足完整性约束条件，数据库系统将不再执行用户的操作。

约束条件如下表：

| 约束条件       | 说明                                           |
| -------------- | ---------------------------------------------- |
| PRIMARY KEY    | 标识该属性为该表的主键，可唯一标识对应元组     |
| FOREIGN KEY    | 标识该属性为该表的外键，是与之联系的某表的主键 |
| NOT NULL       | 标识该属性不能为空                             |
| UNIQUE         | 标识该属性值唯一                               |
| AUTO_INCREMENT | 标识该属性值自动增加（MySQL特有）              |
| DEFAULT        | 为该属性设置默认值                             |

#### 5.1.3.1 设置表字段的主键约束（PK）

**PRIMARY KEY**，主键的主要目的是帮助数据库管理系统以最快的速度查找到表的某一条信息。主键必须满足的条件就是主键必须是唯一的，表中任意两条记录的主键字段的值不能相同，并且是非空值。主键可以是单一的字段，也可以是多个字段的组合。

##### 单字段主键

```mysql
#创建数据库school
mysql> create database school; 
#选择数据库school 
mysql> use school;   
#创建表class （id为主键约束）
mysql> create table class(id int PRIMARY KEY, name varchar(128), teacher varchar(64));   #查询表class 的定义, 与 describe class 效果等同     
mysql> desc class ;  
#查询表class 的定义语句
mysql> show create table class ;  
#以下插入成功
mysql> insert into class VALUES(1,'一班','martin');
#因主键约束，以下插入失败
mysql> insert into class VALUES(1,'二班','rock');    
```

##### 多字段主键

在属性定义完成后，统一设置主键。

```mysql
#创建数据库school
mysql> create database school;   
#选择数据库school 
mysql> use school;   
#创建表class,设置联合主键，使用 CONSTRAINT 为主键设置名字（MySQL特有）
mysql> create table class(id int, name varchar(128), teacher varchar(64), CONSTRAINT id_pk PRIMARY KEY(id,name));  
#查询表class 的定义, 与 describe class 效果等同
mysql> desc class ;
#以下插入成功
mysql> insert into class VALUES(1,'一班','martin');  
#因联合主键约束，以下插入失败
mysql> insert into class VALUES(1,'一班','rock');    
```

#### 5.1.3.2 设置表的外键约束（FK）

**FOREIGN KEY**，外键保证多个表（通常为两个表）之间的参照完整性，即构建两个表的字段之间的参照关系。设置外键约束的两个表之间具有父子关系，即子表中某个字段的取值范围由父表决定；如：班级表和学生表，学生表的班级编号字段no依赖于班级表的主键，如此，字段no为学生表的外键，通过该字段班级表与学生表建立了联系。

```mysql
#选择数据库school 
mysql> use school;   
#创建表class 
mysql> create table class(id int PRIMARY KEY, name varchar(128), teacher varchar(64));
#查询表class 的定义, describe class 效果等同
mysql> desc class ;  
#插入记录
mysql> insert into class VALUES(1,'一班','martin');  
mysql> insert into class VALUES(2,'二班','rock');    
#创建表student, class_id 为表class id 字段的外键 
mysql> create table student (id int PRIMARY KEY AUTO_INCREMENT, name varchar(64) NOT NULL, class_id int, sex enum('M','F'), FOREIGN KEY(class_id) REFERENCES class(id) ); 
#插入记录，主键自增长，外键必须存在。
mysql> insert into student(name, class_id, sex) values('小白', 2, 'M');
#插入记录，允许外键为空 
mysql> insert into student(name, sex) values('小黑', 'M');   
```

#### 5.1.3.3 设置表字段的非空约束（NK）

**NOT NULL**，当数据库表中的某个字段上的内容不希望设置为NULL时，可以使用NK约束进行设置。NK约束在创建数据库表时为某些字段上加上"NOT NULL"约束条件，保证所有记录中的该字段都有值。如果在用户插入的记录中该字段为空值，那么数据库管理系统会报错。

```mysql
#创建数据库school
mysql> create database school;   
#选择数据库school 
mysql> use school;   
#创建表class
mysql> create table class(id int, name varchar(128) NOT NULL, teacher varchar(64)); 
#查询表class 的定义, describe class 效果等同 （查询字段是否为NK约束）
mysql> desc class ;  
#查询表class 的定义语句
mysql> show create table class ;  
```

#### 5.1.3.4 设置表字段的唯一约束（UK）

**UNIQUE**，当数据库表中某个字段上的内容不允许重复时，可以使用UK约束进行设置。UK约束在创建数据库时为某些字段加上“UNIQUE”约束条件，保证所有记录中该字段上的值不重复。如果在用户插入的记录中该字段上的值与其他记录中该字段上的值重复，那么数据库管理系统会报错。被约束的字段出现多个空值NULL，不算重复。

```mysql
#创建数据库school
mysql> create database school; 
#选择数据库school 
mysql> use school;   
#创建表class
mysql> create table class(id int, name varchar(128) UNIQUE, teacher varchar(64));  
#查询表class 的定义, 与 describe class 效果等同 
mysql> desc class ;  
#同样可以实现查询表class 的定义 
mysql> show create table class ;  
```

#### 5.1.3.5 设置表字段值自动增加

**AUTO_INCREMENT**，MySQL唯一扩展的完整性约束，当向数据库表中插入新记录时，字段上的值会自动生成唯一的ID。在具体设置AUTO_INCREMENT约束时，一个数据库表中只能有一个字段使用该约束，该字段的数据类型必须是整数类型。由于设置AUTO_INCREMENT约束后的字段会生成唯一的ID，因此该字段也经常会同时设置成PK主键。

```mysql
#创建数据库school
mysql> create database school;  
#选择数据库school 
mysql> use school;   
#创建表class,设置字段id为自增长
mysql> create table class(id int PRIMARY KEY AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64)); 
#查询表class的定义 
mysql> desc class ;  
```

注：在mysql8.0中，AUTO_INCREMENT 必须设为键（主键、外键、唯一键）。

#### 5.1.3.6 设置表字段的默认值

**DEFAULT**，当为数据库表中插入一条新记录时，如果没有为某个字段赋值，数据库系统就会自动为这个字段插入默认值。若未设置默认值时，默认为空。

```mysql
CREATE TABLE table_name(
    propName propType DEFAULT defaultvalue, ......
);
```

#### 5.1.3.7 设置列的完整性约束

**修改主键、外键、唯一键**

- 新增

```mysql
alter table [table_name] add constraint [constraint_name 约束名称] [unique key| primary key|foreign key] ([column_name 列名])
```

- 删除

```mysql
#查询键值约束名
show index 或 keys from 表名;
#删除主键
alter table 表名 drop primary key;
#删除外键或唯一键 
alter table 表名 drop index 约束名; 
```

- 修改

```mysql
#先删除再新增
```

**修改默认值DEFAULT、自增长和非空**

```mysql
alter 表名 modify 列名 类定义;

#创建数据库school
mysql> create database school;
#选择数据库school 
mysql> use school;   
#创建表class,设置字段id为自增长
mysql> create table class(id int PRIMARY KEY AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64));   
#设置默认值和非空
mysql> alter table class modify teacher varchar(64) DEFAULT 'Martin' NOT NULL ;  
#取消默认值和非空
mysql> alter table class modify teacher varchar(64) ; 
```

### 5.1.4 表索引

#### 5.1.4.1 索引概念

索引是一种特殊的数据库结构，可以用来快速查询数据库表中的特定记录，是提高数据库性能的重要方式。MySQL中，所有的数据类型都可以被索引。通过索引，查询数据时可以不必读完记录的所有信息，而只是查询索引列，否则数据库系统将读取每条记录的所有信息进行匹配。使用索引可以在很大程度上提高数据库的查询速度，有效地提高了数据库系统的性能。

**索引类型**

索引包括普通索引、唯一性索引、全文索引、单列索引、多列索引和空间索引等。

**索引存储**

数据库底层索引实现主要有两种存储类型，B树(BTREE)和哈希(HASH)索引，InnoDB和MyISAM 使用BTREE索引；而MEMORY 存储引擎可以使用BTREE 和HASH 索引，默认用BTREE。在没有指定的情况下，数据库使用的引擎是 InnoDB。

**索引优点**

提高检索数据的速度。

**使用建议**

索引可以提高查询的速度，但是会影响插入记录的速度，因为向有索引的表中插入记录时，数据库系统会按照索引进行排序，这样就降低了插入记录的速度，插入大量记录时的速度影响更加明显。这种情况下，最好的办法是先删除表中的索引，然后插入数据，插入完成后再创建索引。

#### 5.1.4.2 创建和查看索引

创建索引是指在某个表的一列或多列上建立一个索引，以便提高对表的访问速度。创建索引有3种方式，分别是创建表的时候创建索引、在已经存在的表上创建索引和使用ALTER TABLE语句来创建索引。

**普通索引**
在创建索引时，不附加任何限制条件（唯一、非空等限制），该类型的索引可创建在任何数据类型的字段上。

- 创建表时定义索引``` INDEX | KEY [indexname] (propnamen [(length)] [ ASC | DESC ] ) ```
  - INDEX 和 KEY： 用来指定字段为索引，二者选其一。
  - indexname：索引名称。
  - propnamen：被索引的字段名称，要求已定义。
  - length：可选参数，索引长度，字符串类型可用。
  - ASC 和 DESC：可选参数，ASC表示升序排列，DESC表示降序排列，不指定时默认为升序。

```mysql
#创建数据库school
create database school;
#选择数据库school
use school;
#创建表class, 并为 id 字段建立索引（索引名为index_no），
create table class(id int, name varchar(128) UNIQUE, teacher varchar(64), INDEX index_no(id DESC));
#查看表结构
show create table class;
insert into class values(1, '一班', 'Martin'); 
insert into class values(1, '二班', 'Rock');  
#根据id查询记录，结果将降序排列  
select * from class where id > 0 ;   
```

- 已存在的表上创建索引

```mysql
# 方法一：执行creat语句
#创建数据库school  
create database school;
#选择数据库school
use school;
#创建表class, 并建立为id 字段索引  
create table class(id int, name varchar(128) UNIQUE, teacher varchar(64));
#追加升序索引 
create index index_id on class(id ASC);   
show create table class;  
insert into class values(2, '一班', 'Martin');
insert into class values(1, '二班', 'Rock');  
#根据id查询记录，结果将降序排列  
select * from class where id > 0 ;   

# 方法二：执行ALTER TABLE语句
#格式：ALTER TABLE tablename ADD INDEX | KEY indexname (propname [(length)] [ASC|DESC]);
ALTER TABLE class ADD INDEX index_id (id ASC);
```

- EXPLAIN查看索引执行情况
  - key：实际使用的索引
  - possible_keys：可能应用在此表中的索引
  - key_len：索引中使用的字节数

```mysql
explain select * from class where id > 0;
```

**唯一索引**

在创建索引时，限制索引的字段值必须是唯一的。通过该类型的索引可以比普通索引更快速地查询某条记录。

- 创建表时定义索引：```UNIQUE INDEX | KEY [indexname] (propnamen [(length)] [ ASC | DESC ] )```
  - UNIQUE INDEX 和 UNIQUE KEY：用来指定字段为索引，二者选其一。
  - indexname：索引名称。
  - propnamen：被索引的字段名称，要求已定义为UNIQUE约束。
  - length：可选参数，索引长度，字符串类型可用。
  - ASC 和 DESC：可选参数，ASC表示升序排列，DESC表示降序排列，不指定时默认为升序。

```mysql
CREATE TABLE class(UNIQUE id int, name varchar(128) UNIQUE, teacher varchar(64), UNIQUE INDEX index_no(id DESC));
```

- 已存在的表上创建索引：

```mysql
# 方法一：执行creat语句
CREATE UNIQUE INDEX indexname ON tablename (propname [(length)] [ASC|DESC]);  

# 方法二：执行ALTER TABLE语句
ALTER TABLE tablename ADD UNIQUE INDEX | KEY indexname (propname [(length)] [ASC|DESC]);
```

**全文索引**

全文索引主要对字符串类型建立基于分词的索引，主要是基于CHAR、VARCHAR和TEXT的字段上，以便能够更加快速地查询数据量较大的字符串类型的字段。全文索引以词为基础，MySQL默认的分词是所有非字母和数字的特殊符号。默认情况下，全文索引的搜索方式不区分大小写，若全文搜索关联的字段为二进制数据类型，则以区分大小写的搜索方式执行。

- 创建表时定义索引

```mysql
#创建数据库school  
create database school;  
#选择数据库school  
use school;   
#创建表class, 并为comment 字段建立全文索引  
create table class(id int, name varchar(128) UNIQUE, teacher varchar(64),comment varchar(1024),FULLTEXT INDEX index_comm(comment));
insert into class values(1,'1班','Martin','我是Martin，来自朔北。'); 
insert into class values(2,'2班','Rock','我是Rock，来自滇西。');
insert into class values(3,'3班','Kevin','我是Kevin，来自长安。');
#利用全文检索索引快速查询记录
select * from class where match(comment) AGAINST('我是Kevin');
```

- 已存在的表上创建索引

```mysql
# 方法一：执行creat语句
create table class(id int, name varchar(128) UNIQUE, teacher varchar(64));
create FULLTEXT index index_teacher on class(teacher );  

# 方法二：执行ALTER TABLE语句
ALTER TABLE tablename ADD FULLTEXT INDEX | KEY indexname (propname [(length)] [ASC|DESC]);
```

> 中文分词支持：
>
> 1.修改MySQL8配置文件my.ini
>
> ```ini
> [mysqld]
> 
> ngram_token_size=2
> ```
>
> 2.重启MySQL服务。

**多列索引**

在创建索引时所关联的字段不是一个字段，而是多个字段，虽然可以通过所关联的字段进行查询，但是只有查询条件中使用了所关联字段中的第一个字段，多列索引才会被使用。和普通索引定义基本相同，不同之处就是增加了多个索引列。

- 创建表时定义索引

```mysql
#创建表class, 并建立包含id,teacher字段的多列索引 
create table class(id int, name varchar(128) UNIQUE, teacher varchar(64), INDEX index_mult_columns(id, teacher));      
#仅根据id查询记录会启用多列索引 
select * from class where id > 0 ; 
```

- 已存在的表上创建索引

```mysql
# 方法一：执行creat语句
#创建表class, 并建立为id 字段索引  
create table class(id int, name varchar(128) UNIQUE, teacher varchar(64));   
#追加多列索引  
create index index_id on class(id, name );  

# 方法二：执行ALTER TABLE语句
ALTER TABLE tablename ADD FULLTEXT INDEX | KEY indexname (propname1 [(length)] [ASC|DESC], propname2 [(length)] [ASC|DESC], propname3 [(length)] [ASC|DESC]);
```

**隐藏索引**

MySQL 8开始支持隐藏索引，隐藏索引可以用来测试索引的性能。验证索引的必要性时不需要删除索引，可以先将索引隐藏，如果优化器性能无影响就可以真正地删除索引。

```mysql
#隐藏索引
ALTER TABLE tablename ALTER  INDEX  index_name INVISIBLE;  
#取消隐藏
ALTER TABLE tablename ALTER  INDEX  index_name VISIBLE;    
```

**删除索引**

索引会降低表的更新速度，影响数据库的性能。

```mysql
DROP INDEX indexname ON tablename; 
```

> 修改索引：删除再增加。

#### 5.1.4.3 索引的设计原则

1. 选择唯一性索引：被索引字段的值唯一，快速定位。
2. 为经常需要排序、分组和联合操作的字段建立索引：常被ORDER BY、GROUP BY、DISTINCT和UNION等操作的字段，排序会浪费时间，为其建立索引可有效地避免排序操作。
3. 为经常作为查询条件的字段建立索引：该字段的查询速度影响着整个表的查询速度。
4. 限制索引数目：索引过多时，需要更多的磁盘空间，修改表时，对索引重构和更新困难。
5. 尽量使用数据量少的索引。
6. 尽量使用前缀来索引。
7. 删除不再使用或很少使用的索引。

## 5.2 表的插入

### 5.2.1 插入完整数据记录

语法：

```mysql
# 插入完整数据：其中field为字段名，value为要插入的值。
INSERT INTO tablename(field1, field2, ..., fieldn) VALUES(value1, value2, ..., valuen);
# 简写
INSERT INTO tablename VALUES(value1, value2, ..., valuen);
```

示例：

```mysql
create database school;
use school;
create table class(id int, name varchar(128) UNIQUE, teacher varchar(64));
# 插入完整记录
insert into class(id, name, teacher) values(1, '一班', 'Martin');  
# 插入完整记录（缩写）
insert into class values(2, '二班', 'Rock'); 
```

### 5.2.2 插入部分数据记录

语法：

```mysql
INSERT INTO tablename(field1, field3) VALUES(value1, value3);
#若字段未设置默认值或自增长，则插入记录时必须插入值
```

示例：

```mysql
create database school;
use school;
# 字段id自增长
create table class(id int UNIQUE AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64));
insert into class(id, name, teacher) values(1, '一班', 'Martin');
insert into class (name, teacher) values('二班', 'Rock');
```

### 5.2.3 插入多条数据记录

语法：

```mysql
INSERT INTO tablename(field1, field2, field3, ..., fieldn) 
VALUES(value11, value12, value13, ..., value1n)，   
(value21, value22, value23, ..., value2n)，          
... ....                                             
(valuen1, valuen2, valuen3, ..., valuenn);     
```

示例：

```mysql
create database school;
use school;
# 字段id自增长
create table class(id int UNIQUE AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64)); 
# 插入多条记录 
insert into class(id, name, teacher) values(1, '一班', 'Martin'),(2,'二班', 'Rock'),(3, '三班', 'Janny');  
```

### 5.2.4 插入Json数据记录

## 5.3 更新表中的数据记录

### 5.3.1 更新特定数据记录

语法：

```mysql
UPDATE tablename SET field1 = value1, field2 = value2, field3 = value3, ..., fieldn = valuen) WHERE CONDITION;
# CONDITION 指满足更新条件的特定数据记录
```

示例：

```mysql
create database school;
use school; 
create table class(id int UNIQUE AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64));
insert into class(id, name, teacher) values(1, '一班', 'Martin'),(2,'二班', 'Rock'),(3, '三班', 'Janny');  
#通过 teacher 字段匹配更新记录
update class set teacher = 'Kevin' where teacher = 'Rock';
#通过 id 字段匹配更新记录
update class set teacher = 'Kevin' where id = 2;  
```

### 5.3.2 更新所有数据记录

语法：

```mysql
UPDATE tablename SET field1 = value1, field2 = value2, field3 = value3, ..., fieldn = valuen) WHERE CONDITION;

UPDATE tablename SET field1 = value1, field2 = value2, field3 = value3, ..., fieldn = valuen);
```

示例：

```mysql
create database school;
use school;
create table class(id int UNIQUE AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64));
insert into class(id, name, teacher) values(1, '一班', 'Martin'),(2,'二班', 'Rock'),(3, '三班', 'Janny');
update class set teacher = 'Kevin' ;      
update class set teacher = 'Kevin' where 1=1;  
```

## 5.4 删除表中的数据记录

### 5.4.1 删除表中特定数据记录

语法：

```mysql
DELETE FROM tablename WHERE CONDITION;
```

示例：

```mysql
create database school;
use school;
create table class(id int UNIQUE AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64));
insert into class(id, name, teacher) values(1, '一班', 'Martin'),(2,'二班', 'Rock'),(3, '三班', 'Janny');
delete from class where teacher = 'Martin';
delete from class where id = 1;
```

### 5.4.2 删除表中所有数据记录

语法：

```mysql
DELETE FROM tablename WHERE CONDITION;
DELETE FROM tablename；
```

示例：

```mysql
create database school;
use school;
create table class(id int UNIQUE AUTO_INCREMENT, name varchar(128) UNIQUE, teacher varchar(64));
insert into class(id, name, teacher) values(1, '一班', 'Martin'),(2,'二班', 'Rock'),(3, '三班', 'Janny');
delete from class ;
delete from class where id > 0;
```

# 六、数据查询

## 6.1 简单查询

创建测试数据：

```mysql
DROP DATABASE school;
CREATE DATABASE IF NOT EXISTS school;
USE school;

DROP TABLE class;
CREATE TABLE IF NOT EXISTS class(
    id INT UNIQUE AUTO_INCREMENT, 
    name VARCHAR(128) UNIQUE, 
    teacher VARCHAR(64));
INSERT INTO class(id, name, teacher) VALUES
(1, '一班', 'Martin'),
(2, '二班', 'Rock'),
(3, '三班', 'Janny'),
(4, '四班', 'Janny');

DROP TABLE grade;
CREATE TABLE IF NOT EXISTS grade(
    id INT UNIQUE AUTO_INCREMENT, 
    class_id TINYINT UNSIGNED, 
    name VARCHAR(128) NOT NULL, 
    math TINYINT UNSIGNED, 
    chinese TINYINT UNSIGNED, 
    english TINYINT UNSIGNED, 
    create_date  DATE); 
INSERT INTO grade VALUES
(1, 1, '甲', 80, 87, 91, '2020-02-03'),
(2, 2, '乙', 72, 64, 89, '2020-05-01'),
(3, 2, '丙', 54, 69, 87, '2020-04-21'),
(4, 1, '丁', 78, 79, 89, '2020-06-04');
```

***查询所有字段数据***

```mysql
SELECT * FROM class;
```

***查询指定字段数据***

```mysql
SELECT teacher FROM class;
```

***DISTINCT查询：查询结果去重***

```mysql
SELECT DISTINCT teacher FROM class; 
```

***IN查询：查询的目标记录在某个集合中***

```mysql
# 查询class表中的 teacher域 是 martin和Rock 的记录   
SELECT * FROM class WHERE teacher IN ('Martin','Rock'); 

# 使用NOT IN可以反向查询非集合中的数据，此时被查询的集合不能存在NULL，否则查询无果。
SELECT * FROM class WHERE teacher NOT IN ('Martin','Rock'); 
```

***BETWEEN AND查询：查询指定范围的数据***

```mysql
SELECT * FROM grade WHERE chinese BETWEEN  80 AND 90;
SELECT * FROM grade WHERE create_date BETWEEN '2020-05-01' AND '2020-06-04';

# 不符合范围的数据记录的查询：通过NOT关键字设置反向查询费查询范围的条件
SELECT `name`, chinese FROM grade WHERE chinese NOT BETWEEN 85 AND 90;
SELECT `name`, chinese FROM grade WHERE chinese < 85 OR chinese > 90;
```

***LIKE模糊查询：通过通配符进行模糊查询***

```mysql
# 通配符 _ ：匹配单个字符。
# 通配符 % ：匹配任意长度的字符串，不区分大小写；若匹配"%%"，则表示查询所有记录。

# 查询 teacher字段 中含有"三"的记录。
SELECT * FROM class WHERE teacher LIKE '%三%';
# 查找 teacher字段 中同时含有"三"和"猫"的记录，使用and条件。
SELECT * FROM class WHERE teacher LIKE '%三%' AND teacher LIKE '%猫%';
# 查询 teacher字段 中同时含有"三"和"猫"且"猫"在"三"之后的记录。
SELECT * FROM class WHERE teacher LIKE '%三%猫%';
# 查询 u_name字段 中为三个字符且第二个字符为"三"的记录。
SELECT * FROM `user` WHERE u_name LIKE '_三_';
```

***对查询结果排序***

```mysql
#按升序的方式查询学员记录 
SELECT id,`name`, chinese FROM grade ORDER BY chinese ASC; 
```

***简单分组查询***

```mysql
# 语法：SELECT function(filedn) FROM tablename WHERE CONDITION GROUP BY field1;
# 1.统计数量：COUNT(*)，统计所有记录，不忽略NULL值；COUNT(field)，统计指定字段记录，忽略NULL值。	
# 2.统计计算平均值，AVG(field)：计算指定字段的平均值，忽略NULL值。	
# 3.统计计算求和，SUM(field)：计算指定字段的和值，忽略NULL值。	
# 4.统计最大值，MAX(field)：计算指定字段的最大值，忽略NULL值。	
# 5.统计最小值，MIN(field)：计算指定字段的最小值，忽略NULL值。	

# 对两个班级的数学成绩进行统计 	
SELECT id, `name`, sum(math) FROM grade GROUP BY id; 
# 统计平均分，会忽略掉NULL 记录
SELECT class_id, avg(math), avg(chinese), avg(english) FROM grade GROUP BY class_id;  
```

***统计分组查询***

```mysql
# 对每个班级的math成绩分别求和
SELECT GROUP_CONCAT(`name`) `name`, sum(math) FROM grade GROUP BY class_id; 
```

## 6.2 联合查询

将两个或多个表中相同字段的记录关联起来组成新的列表，即为联合查询。

### 6.2.1 内连接查询

> 内连接（INNER JOIN ... ON）：A表的所有行交上B表的所有行得出的结果集。

构建数据：

```mysql
DROP DATABASE IF EXISTS school;
CREATE DATABASE IF NOT EXISTS school;                           
USE school;                                    
CREATE TABLE class (                                                        
  `id` INT NOT NULL AUTO_INCREMENT,                                              
  `name` VARCHAR(128) DEFAULT NULL,                                               
  `teacher` VARCHAR(64) DEFAULT NULL,                                               
  UNIQUE KEY `id` (`id`)                                                              
);                                                                
INSERT INTO class VALUES(101, '萌新一班', 'Martin'),(102, '萌新二班', 'Rock'),(103, '萌新三班', 'Janny'); 

DROP TABLE IF EXISTS student;
CREATE TABLE IF NOT EXISTS student (                                                  
  `id` INT NOT NULL AUTO_INCREMENT UNIQUE,     
  `name` VARCHAR(64) DEFAULT NULL,                                                
  `class_id` INT DEFAULT NULL,                                                      
  `sex` ENUM('F','M') DEFAULT NULL                                                  
);                                                                                   
INSERT INTO student VALUES(1,'小花',101,'M'),(2,'小红',102, 'F'),(3,'小军',102,'F'),(4,'小白',101,'F'); 
#查询class 表和student 表中班级字段相同的记录并进行内连接  
SELECT * FROM class INNER JOIN student ON class.id = student.class_id;  
#同上，使用别名查询
SELECT * FROM class AS a INNER JOIN student AS b WHERE a.id = b.class_id; 
```

> 表名过长或实现自连接操作时直接使用表名无法区分表，故MySQL提供了别名机制来解决此类问题。

***自连接：表与自身进行连接***

```mysql
# 查询学生 "小红" 所在班级的其他学生 
SELECT t1.id, t1.name, t1.class_id FROM student t1 INNER JOIN student t2 ON t1.class_id = t2.class_id AND t2.name = '小红';
```

***等值连接：在关键字ON后的匹配条件中通过等于关系运算符来实现等值条件***

```mysql
SELECT * FROM class AS a INNER JOIN student AS b WHERE a.id = b.class_id; 
```

***不等值连接：在关键字ON后的匹配条件中通过等于关系运算符来实现等值条件，还可使用其他关系运算符***

```mysql
SELECT * FROM class AS a INNER JOIN student AS b WHERE a.id != b.class_id; 
```

### 6.2.2 外连接查询

> 外连接（OUTER JOIN ... ON）：返回所操作表中至少一个表的所有数据记录。

***左外连接：A表的所有行匹配上B表得出的结果集。***

```mysql
# 左连接查询所有学生对应的班级信息
SELECT * FROM student AS a LEFT JOIN class AS b ON a.class_id = b.id; 
# 左连接查询所有班级的学员信息
SELECT * FROM class AS a LEFT JOIN student AS b ON a.id = b.class_id; 
```

***右外连接：B表的所有行匹配上A表得出的结果集。***

```mysql
# 右连接查询所有班级对应的学员信息
SELECT * FROM student AS a RIGHT JOIN class AS b ON a.class_id = b.id; 
# 右连接查询所有学员对应的班级信息
SELECT * FROM class AS a RIGHT JOIN student AS b ON a.id = b.class_id;
```

***全连接：A表的所有行并上B表的所有行得出的结果集（MySQL不支持）。***

```mysql
# MySQL不支持全连接，以下语句无效
SELECT * FROM student AS a FULL JOIN class AS b ON a.class_id = b.id;
# 通过左连接+union+右连接实现全连接
SELECT * FROM student AS a LEFT JOIN class AS b ON a.class_id = b.id 
UNION 
SELECT * FROM student AS a RIGHT JOIN class AS b ON a.class_id = b.id;
```

***交叉连接：交叉联接返回左表中的所有行，左表中的每一行与右表中的所有行组合。交叉联接也称作笛卡尔积。***

```mysql
SELECT * FROM student AS a CROSS JOIN class AS b ORDER BY a.class_id;
```

### 6.2.3 合并查询数据记录

在MySQL中通过关键字UNION来实现合并操作，即可以通过其将多个SELECT语句的查询结果合并在一起，组成新的关系。多个选择语句select 的列数相同就可以合并，union和union all的主要区别是union all是把结果集直接合并在一起，而union 是将union all后的结果再执行一次distinct，去除重复的记录后的结果。

```mysql
# 查询班级表所有老师和学生表中所有学生姓名 
SELECT teacher FROM class UNION ALL SELECT `name` FROM student; 
# 同上，使用别名查询 
SELECT teacher AS people FROM class UNION ALL SELECT `name` AS people FROM student; 
# 查询班级表所有(老师、班级ID)和学生表中所有学生(姓名、班级ID) 
SELECT teacher, id FROM class UNION ALL SELECT `name`, class_id FROM student; 
```

### 6.2.4 子查询

> 子查询，是指在一个查询中嵌套了其他的若干查询，即在一个SELECT查询语句的WHERE或FROM子句中包含另一个SELECT查询语句。在查询语句中，外层SELECT查询语句称为主查询，WHERE子句中的SELECT查询语句被称为子查询，也被称为嵌套查询。通过子查询可以实现多表查询，该查询语句中可能包含IN、ANY、ALL和EXISTS等关键字，除此之外还可能包含比较运算符。理论上，子查询可以出现在查询语句的任意位置，但是在实际开发中子查询经常出现在WHERE和FROM子句中。

***带比较运算符的子查询：比较运算符包括=、!=、>、>=、<、<=和<>等。其中，<>与!=等价。***

```mysql
# 查询“小花”所在班级班主任的姓名 
SELECT teacher FROM class WHERE id = (SELECT class_id FROM student WHERE `name`='小花'); 
```

***带关键字IN的子查询：一个查询语句的条件可能落在另一个SELECT语句的查询结果中，可使用IN关键字。***

```mysql
# 查询student 表中“小花”所在班级班主任的名字
SELECT teacher FROM class WHERE id IN (SELECT class_id FROM student WHERE `name`='小花');    
# 查询姓名以“小”字开头的学生所在班级班主任的姓名  
SELECT teacher FROM class WHERE id IN (SELECT class_id FROM student WHERE `name` LIKE '小%'); 
```

***带关键字EXISTS的子查询：对子查询进行判断是否返回行，如是则进行外层查询，否则外层语句不进行查询。***

```mysql
# 如果102班存在学生记录，就查询102班的班级信息 
SELECT * FROM class WHERE id = 102 AND EXISTS (SELECT * FROM student WHERE class_id = 102); 
```

***带关键字ANY的子查询：只要满足内层查询语句返回的结果中的任何一个就可以通过该条件来执行外层查询语句。***

```mysql
# 使用简单查询中的测试数据
CREATE TABLE scholarship (score INT, `level` VARCHAR(64));      
INSERT INTO scholarship VALUES(240, '二等奖'),(257,'一等奖');
# 查询能获得奖学金的学院记录 
SELECT grade.id, grade.name, grade.math + grade.chinese + grade.english TOTAL FROM grade WHERE (math + chinese + english) >= ANY (SELECT score FROM scholarship); 
```

***带关键字ALL的子查询：只有满足内层查询语句返回的所有结果才可以执行外层查询语句。***

```mysql
# 查询能获得一等奖学金的同学记录
SELECT grade.id, grade.`name`, grade.math + grade.chinese + grade.english TOTAL FROM grade WHERE (math + chinese + english) >= ALL (SELECT score FROM scholarship);
# 查询不能获得奖学金的同学记录
SELECT grade.id, grade.`name`, grade.math + grade.chinese + grade.english TOTAL FROM grade WHERE (math + chinese + english) < ALL (SELECT score FROM scholarship);
```

# 七、视图操作

视图是从一个或多个表中导出来的表，是一种虚拟表，在物理上并不存在。视图就像一个窗口，通过这个窗口可以看到系统专门提供的数据，这样用户可以不看整个数据库表中的数据，而只关心对自己有用的数据。视图可以使用户的操作更方便，而且可以保障数据库系统的安全性。

## 7.1 创建视图

创建视图需要登录用户有相应的权限，查看权限方法：

```mysql
USE school;  
# 查询数据库用户创建和选择视图权限 
SELECT user, Select_priv, Create_view_priv FROM mysql.user;
```

在表上创建视图：

```mysql
# 增加私隐列
ALTER TABLE student ADD privacy VARCHAR(64);
# 查询数据库用户创建和选择视图权限
# 为学生表创建视图 
CREATE VIEW view_student AS SELECT id, class_id, `name` FROM student ;
#查看视图 
DESC view_student;
#根据视图进行查询  
SELECT * FROM view_student; 
```

# 八、触发器

# 九、存储过程和函数

# 十、存储引擎

# 十一、C/C++访问MySQL

- 步骤一：打开MySQL安装目录，确保lib目录和include目录存在。

- 步骤二：VS下新建C++工程（控制台应用），解决方案平台选择x64。

- 步骤三：为工程配置MySQL头文件和库文件。

  - 工程属性页配置头文件和库文件目录。

    ```
    VC++目录 => 包含目录 => E:\App\MySQL\MySQL Server 8.0\include
    VC++目录 => 库目录 => E:\App\MySQL\MySQL Server 8.0\lib
    链接器 => 输入 => 附加依赖项 => libmysql.lib
    ```

- 步骤四：复制动态链接库到系统目录。

  - 复制mysql安装目录下的```lib\libmysql.dll```复制到```c:\windows\system32```。

- 步骤五：使用数据库。

  ```c++
  #include <iostream>
  #include <mysql.h>
  
  int main(void)
  {
  	MYSQL mysql;    //数据库句柄
  	MYSQL_RES* res; //查询结果集
  	MYSQL_ROW row;  //记录结构体
  
  	//初始化数据库
  	mysql_init(&mysql);
  
  	//设置字符编码
  	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
  
  	//连接数据库
  	if (mysql_real_connect(&mysql, "127.0.0.1", "root", "lc714462439", "school", 3306, NULL, 0) == NULL) 
  	{
  		printf("错误原因： %s\n", mysql_error(&mysql));
  		printf("连接失败！\n");
  		exit(-1);
  	}
  
  	//查询数据
  	int ret = mysql_query(&mysql, "select * from student;");
  	printf("ret: %d\n", ret);
  	//获取结果集
  	res = mysql_store_result(&mysql);
  
  	//给ROW赋值，判断ROW是否为空，不为空就打印数据。
  	while (row = mysql_fetch_row(res))
  	{
  		printf("%s  ", row[0]);  //打印ID
  		printf("%s  ", row[1]);  //打印姓名
  		printf("%s  ", row[2]);  //打印班级
  		printf("%s  \n", row[3]);//打印性别
  	}
  	//释放结果集
  	mysql_free_result(res);
  
  	//关闭数据库
  	mysql_close(&mysql);
  
  	system("pause");
  	return 0;
  }
  ```

# 十二、数据库设计实战

