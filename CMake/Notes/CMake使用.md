环境：

```bash
# Ubuntu
sudo apt install cmake
# Windows
https://github.com/Kitware/CMake/releases/download/v3.20.0-rc1/cmake-3.20.0-rc1-windows-x86_64.msi
```



## 语法特性：

基本语法格式：指令(参数1 参数2...)

- 参数由小括号括起，多个参数使用空格或分号分隔开。

- 指令不区分大小写，参数及变量区分大小写。

  ```cmake
  # 定义变量 HELLO
  set(HELLO hello.cpp)
  add_executable(hello main.cpp ${HELLO})
  ```

- 变量使用${}方式取值，但在IF语句中直接使用变量名。

## 重要指令：

- cmake_minimum_required - 指定CMake的最小版本要求

  - 语法：cmake_minimum_required(VERSION versionNumber[FATAL_ERROR])

  ```cmake
  # CMake最小版本要求为2.8.3
  cmake_minimum_required(VERSION 2.8.3)
  ```

- project - 定义工程名称

  - 语法：project(projectname [CXX] [C] [Java])

  ```cmake
  # 指定工程名为HELLOWORLD
  project(HELLOWORLD)
  ```

- set - 显式的定义变量

  - 语法：set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])

  ```cmake
  # 定义SRC变量，值为 main.cpp hello.cpp
  set(SRC main.cpp hello.cpp)
  ```

- include_directories - 向工程添加多个特定的头文件搜索路径 （g++ -i 参数）

  - 语法：include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2...)

  ```cmake
  # 将/usr/include/myincludefolder 和 ./include 添加到头文件搜索路径
  include_directories(/usr/include/myincludefolder ./include)
  ```

- link_directories - 向工程添加多个特定的库文件搜索路径 （g++ -L 参数）

  - 语法：link_directories(dir1 dir2 ...)

  ```cmake
  # 将/usr/lib/myinlibfolder 和 ./lib 添加到库文件搜索路径
  link_directories(/usr/lib/mylibfolder ./lib)
  ```

- add_library - 生成库文件

  - 语法：add_library(libname [SHARED|STATIC|MODULE]  [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)

  ```cmake
  # 通过变量SRC生成libhello.so共享库
  add_library(hello SHARED ${SRC})
  ```

- add_compile_options - 添加编译参数

  - 语法：add_compile_options(<option> ...)

  ```cmake
  # 添加编译参数 -Wall -std=c++17
  add_compile_options(-Wall -std=c++17 -o2)
  ```

- add_executable - 生成可执行文件

  - 语法：add_executable(exename source1 source2 ... sourceN)

  ```cmake
  # 编译main.cpp生成可执行文件main
  add_executable(main main.cpp)
  ```

- target_link_libraries - 为 target 添加需要链接的动态库 （g++ -I 参数）

  - 语法：target_link_libraries(target library1<debug | optimized> library2...)

  ```cmake
  # 将hello动态库文件链接到可执行文件main
  target_link_libraries(main hello)
  ```

- add_subdirectory - 向当前工程添加存放源文件的子目录，并可指定中间二进制和目标二进制文件的存放的位置

  - 语法：add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])

  ```cmake
  # 添加src子目录，src中需要有一个CMakeLists.txt
  add_subdirectory(src)
  ```

- add_executable - 查询一个目录下所有的源代码文件并以列表存储在变量中，用来临时构建源文件列表

  - 语法：aux_source_directory(dir VARIABLE)

  ```cmake
  # 定义SRC变量，其值为当前目录下所有的源代码文件 
  aux_source_directory(. CURSRC)
  # 编译SRC变量所代表的源代码文件，生成main可执行文件
  add_executable(main_hello ${CURSRC})
  ```

## 常用变量：

- CMAKE_C_FLAGS - gcc编译选项

- CMAKE_CXX_FLAGS - g++编译选项

  ```cmake
  # 在CMAKE_CXX_FLAGS编译选项后追加-std=c++17
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
  ```

- CMAKE_BUILD_TYPE - 编译类型(Debug，Release)

  ```cmake
  # 设置编译类型为debug，调试时选择debug
  set(CMAKE_BUILD_TYPE Debug)
  # 设置编译类型为release，发布时选择release
  set(CMAKE_BUILD_TYPE Release)
  ```

- CMAKE_BINARY_DIR / PROJECT_BINARY_DIR / <projectname>_ BINARY_DIR
  - 指代内容相同。
  - in source build，指工程顶层目录。
  - out of source 编译，指工程编译发生的目录。

- CMAKE_SOURCE_DIR / PROJECT_SOURCE_DIR / <projectname>_ SOURCE_DIR
  - 指代内容相同。
  - 在in source build，同CMAKE_BINARY_DIR 。

- CMAKE_C_COMPILER：指定C编译器。
- CMAKE_CXX_COMPILER：指定C++编译器。
- EXECUTABLE_OUTPUT_PATH：可执行文件输出的存放路径。
- LIBRARY_OUTPUT_PATH：库文件输出的存放路径。

## 编译工程：

CMake目录结构：项目主目录存在一个CMakeLists.txt文件。

两种方式设置编译规则：

1. 包含源文件的子文件夹包含CMakeLists.txt文件，主目录的CMakeLists.txt通过add_subdirectory 添加子目录即可。
2. 包含源文件的子文件夹未包含CMakeLists.txt文件，子目录的编译规则体现在主目录的CMakeLists.txt中。

### 编译流程

#### linux平台

- 手动编写CMakeLists.txt文件。
- 执行cmake PATH生成Makefile（PATH为顶层CMakeLists.txt所在的目录）。
- 执行命令make进行编译。

### 两种构建方式

#### 内部构建(in-source build)

内部构建会在同级目录下产生一大堆中间文件。

```bash
# 在当前目录下，编译本目录的CMakeLists.txt，生成Makefile和其他文件
cmake .
# 执行make命令，生成target
make
```

#### 外部构建(out-of-source build)：推荐使用。

编译输出的文件与源文件在不同目录。

```bash
# 在当前目录下，创建build文件夹
mkdir build
# 进入build文件夹
cd build
# 编译上级目录的CMakeLists.txt，生成Makefile和其他文件
cmake ..
# 执行make命令，生成target
make
```



## 项目实践：

#### HELLO项目

1. 编写CMakeLists.txt

   ```cmake
   # CMake最低版本要求
   cmake_minimum_required(VERSION 3.0)
   
   # 项目名称
   project(HELLO)
   
   # 可执行文件 + 源文件 
   add_executable(helloWorld_cmake helloWorld.cpp)
   ```

2. 构建
   - 内部构建：项目根目录下执行 ```cmake .```构建。
   - 外部构建：新建```build```目录并进入，执行```cmake ..```构建。

#### SWAP项目

CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.0)

project(SWAP)

include_directories(include)

add_executable(main_cmake main.cpp src/swap.cpp)
```

#### SoldierAssault项目

CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.0)

project(SoldierAssault)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O2 -std=c++14")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main_cmake main.cpp src/Gun.cpp src/Solider.cpp)
```

