参考：https://learngitbranching.js.org/?locale=zh_CN

## Github 使用说明

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
git config --global user.name "your name" 	#配置用户名
git config --global user.email "your email" #配置email

# 初始化仓库
git init
# 添加文件
git add .
# 提交到本地代码库
git commit -m "注释"
# 添加远程源repo（新建远程仓库并与本地仓库关联）
git remote add origin git@github.com:Kevin-MRZ/cpp_learning.git # 添加远程源repo
# 提交到远程代码库(master分支)
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

## Git 基础部分

```bash
#提交代码
git commit

#新建分支：newImage
git branch newImage

#切换分支：从main分支到newImage分支
git checkout newImage

#新建分支并切换：新建newImage分支并切换到newImage分支
git checkout -b newImage

#合并分支：将newImage分支合并到main分支
git merge newImage

#合并分支（线性）：将newImage分支合并到main分支
git rebase main

#分离HEAD（哈希码）
git log #查看提交历史，父节点哈希码：c9627fd03cd476edd2d9c9c4118e93d901130dd6）
git checkout c96

#切换到main分支的父节点（相对引用，推荐）
git checkout main^
git checkout ~n	# ~后面的数字n代表向上移动n次，此处应为1

#main分支强制指向HEAD的第三级父提交
git branch -f main HEAD^3

#撤销变更
git reset HEAD~1 #向上回退一个提交记录（该提交记录消失）（本地）
git revert HEAD #以更改的方式撤销提交记录（远程共享），增加新的提交（等同于被撤销提交的上一次提交）


```

## Git 高级部分

```bash
#复制提交到当前位置
git cherry-pick <提交号1> <提交号2>

#UI界面复制操作（排序、删除）
git rebase -i main

#to be continued..
```

