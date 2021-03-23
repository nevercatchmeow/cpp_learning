## Ninja使用

项目根路径下

1. 新建ninja.sh脚本文件

   ```bash
   #!/bin/bash
   
   ROOT_DIR=`pwd`
   if [ -d "$ROOT_DIR/build.ninja" ]; then
       echo "deleting $ROOT_DIR/build.ninja"
       rm -r $ROOT_DIR/build.ninja
   fi
   
   ninja_supported=`cmake --help | grep Ninja`
   
   if [ -z "$ninja_supported" ]; then
       echo "Ninja not supported"
       exit
   fi
   
   mkdir -p build.ninja && cd build.ninja && cmake .. -G Ninja && ninja
   ```

2. 为脚本添加可执行权限

   ```bash
   chmod 744 ninja.sh
   ```

3. 编译（执行脚本）

   ```bash
   ./ninja.sh
   ```

   

