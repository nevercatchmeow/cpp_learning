Git & Github 使用说明
```bash
# 安装Git
sudo apt-get install git

# 生成ssh-key
ssh-keygen -t rsa -C "your_email@youremail.com"
# 绑定Github账户
cat ~/.ssh/id_rsa.pub # 拷贝所有内容粘贴于 ==> Github => SSH and GPG keys => New SSH key
# 验证
ssh -T git@github.com # Success 提示。

# 配置Git
git config --global user.name "your name" //配置用户名
git config --global user.email "your email" //配置email

# 初始化仓库
git init
# 添加文件
git add .
# 提交到本地代码库
git commit -m "注释"
# 添加远程源repo（远程新建仓库并与本地仓库关联）
git remote add origin git@github.com:Kevin-MRZ/cpp_learning.git # 添加远程源repo
# 提交到远程代码库
git push origin master

# 其他
git config --list 	# 获取本地git的配置信息（用户名、邮箱等）

git branch dev	# 创建dev分支
git checkout -b dev		# 创建新分支dev并切换至dev分支
git checkout master 	# 切换到master分支
git branch -a 		# 获取所有分支信息
git remote -v 	# 查看远程repo的地址
git remote rm origin # 删除远程库

# 分支迁移
https://bbs.huaweicloud.com/blogs/228865
```

