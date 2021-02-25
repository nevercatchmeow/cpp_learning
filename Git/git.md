Git & Github 使用说明
```bash
# 安装Git
sudo apt-get install git
# 配置Git
git config –global user.name "your name" //配置用户名
git config –global user.email "your email" //配置email

# 生成ssh-key
ssh-keygen -t rsa -C "your_email@youremail.com"
# 绑定Github账户
cat ~/.ssh/id_rsa.pub # 拷贝所有内容粘贴于 ==> Github => SSH and GPG keys => New SSH key
# 验证
ssh -T git@github.com # Success 提示。

# 初始化仓库
git init
# 添加文件
git add .
# 提交到本地代码库
git commit -m "注释"
# 提交到远程代码库
git push origin master
```
