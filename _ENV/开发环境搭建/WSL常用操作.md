## 远程登录

WSL

```bash
# 重装ssh
sudo apt remove openssh-server
sudo apt install openssh-server
# 修改ssh配置
sudo vim /etc/ssh/sshd_config # 添加以下内容
#--------------------
    Port 2222   #设置ssh端口号, 22端口在windows中被占用
    PermitRootLogin yes   # 允许以root远程登录
    PasswordAuthentication yes     # 密码验证登录
    AllowUsers kevin # 远程登录用户名
#--------------------
# 重启ssh服务
sudo service ssh --full-restart
```

Windows

```
防火墙 => 高级设置 => 入站规则 => 新建规则 => 端口 => tcp => 特定本地端口2222
```

## 重启

Windows Terminal（管理员）：

```powershell
net stop LxssManager
net start LxssManager
```

## 重置

设置 => 应用和功能 => Linux子系统 => 高级选项 => 重置

