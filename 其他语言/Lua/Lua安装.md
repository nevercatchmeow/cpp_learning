Linux：

```bash
# 下载
$ curl -R -O http://www.lua.org/ftp/lua-5.4.2.tar.gz
# 解压
$ tar zxf lua-5.4.2.tar.gz 
# 安装依赖
$ sudo yum install libtermcap-devel ncurses-devel libevent-devel readline-devel
# 编译
$ cd lua-5.4.2
$ make linux
# 安装
$ sudo make install
```

