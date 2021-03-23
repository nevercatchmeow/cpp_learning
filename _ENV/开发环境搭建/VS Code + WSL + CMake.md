参考文档：

```
https://subingwen.cn/vscode/cpp-windows/
```

## 一、安装WSL

启用WSL功能：

```
控制面板 => 启用或关闭Windows功能 => 勾选适用于Linux的Windows子系统。
```

安装（微软官方教程）：

https://docs.microsoft.com/en-us/windows/wsl/install-win10#step-4---download-the-linux-kernel-update-package

可能出现的问题：WSL2-参考的对象类型不支持尝试的操作。

```powershell
# 【临时解决方案】
# Windows PowerShell（管理员）
PS C:\WINDOWS\system32> netsh winsock reset
# 然后重启。

# 【永久解决方案】
# 下载：https://www.proxifier.com/tmp/Test20200228/NoLsp.exe
# Windows PowerShell（管理员）
PS E:\>./NoLsp.exe C:\Windows\System32\wsl.exe
```

## 二、配置WSL

Ubuntu 18.04 LTS：

```bash
# 设置root用户密码
root@LAPTOP-E9TFB9QF:~# passwd root

# 新建用户（例：Kevin）
root@LAPTOP-E9TFB9QF:~# useradd -r -m -s /bin/bash Kevin
root@LAPTOP-E9TFB9QF:~# passwd Kevin
root@LAPTOP-E9TFB9QF:~# chmod u+w /etc/sudoers
root@LAPTOP-E9TFB9QF:~# vim /etc/sudoers
# 添加以下内容：Kevin   ALL=(ALL:ALL) ALL
root@LAPTOP-E9TFB9QF:~# chmod u-w /etc/sudoers

# 配置镜像源（例：阿里镜像源）
root@LAPTOP-E9TFB9QF:~# sed -i s@/archive.ubuntu.com/@/mirrors.aliyun.com/@g /etc/apt/sources.list
root@LAPTOP-E9TFB9QF:~# apt update -y
root@LAPTOP-E9TFB9QF:~# apt upgrade -y

# 安装g++、gdb及cmake
root@LAPTOP-E9TFB9QF:~# apt-get install g++
root@LAPTOP-E9TFB9QF:~# apt-get install gdb
root@LAPTOP-E9TFB9QF:~# apt-get install cmake
```

Windows PowerShell（管理员）：

```powershell
# 设置WSL默认登录用户
PS C:\WINDOWS\system32> ubuntu1804 config --default-user Kevin
```

## 三、VS Code 插件

安装以下插件：

```
- Remote-WSL
- C/C++（WSL）
- CMake（WSL）
- Cmake Tools（WSL）
```

## 四、CMake编译

### 01 新建 CMakeLists.txt 文件。

```cmake
# 项目名称（CPP）
project(CPP)
# 源文件目录（src目录 和 项目根目录）
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)
# 指定所需源文件目录以生成可执行文件helloworld
add_executable(helloworld ${SRC_SUB} ${SRC_CUR})
# 头文件目录（如果有多个使用空格分隔）
include_directories(include)
```

### 02 配置cmake

Ctrl+Shift+P 搜索 cmake:configure，选择g++版本（WSL），等待生成 build 目录。

### 03 编译项目

进入build目录，执行以下：

```bash
cmake ..
make
# MinGW环境下使用 mingw32-make.exe
```

## 五、CMake调试

选择 调试 => 生成配置文件。

tasks.json

```json
{
    "version": "2.0.0",
    "options": {
        "cwd": "${workspaceFolder}/build/"
    },

    "tasks": [
        {
            "label": "cmake",
            "type": "shell",
            "command": "cmake",
            "args": [
                ".."
            ]
        },
        {
            "label": "make",
            "group":{
                "kind":"build",
                "isDefault":true
            },
            // Windows
            // "command": "mingw32-make.exe",
            // Linux
            "command": "make",
            "args":[
            ]
        },
        {
            "label":"Build project",
            "dependsOn":[
                "cmake",
                "make"                
            ]
        }
    ]
}
```

launch.json

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++-7 - 生成和调试活动文件",
            "type": "cppdbg",
            "request": "launch",
            // 修改此项（可执行文件路径）
            // Windows
            // "program": "${workspaceFolder}/build/main_cmake.exe",
            // Linux
            "program": "${workspaceFolder}/build/main_cmake",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "console": "externalTerminal",
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            // 修改此项
            "preLaunchTask": "Build project",
            // Windows
            // "miDebuggerPath": "E:\\App\\MinGW\\bin\\gdb.exe"
            // Linux
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```

