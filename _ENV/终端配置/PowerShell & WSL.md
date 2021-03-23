先安装Windows Terminal，后续PowerShell及WSL终端统一在Windows Terminal中打开。

## WSL终端

WSL字体安装（Hack Nerd Font）：

```bash
sudo apt install unzip
sudo apt install ttf-mscorefonts-installer
sudo apt install fontconfig

wget -c wget -c https://github.com/ryanoasis/nerd-fonts/releases/download/v2.1.0/Hack.zip
sudo unzip Hack.zip -d /usr/share/fonts/Hack
cd /usr/share/fonts/Hack
sudo mkfontscale # 生成核心字体信息
sudo mkfontdir # 生成字体文件夹
sudo fc-cache -fv # 刷新系统字体缓存
```

配置ZSH：

```bash
# 安装zsh
sudo apt install zsh
# 修改默认sh
sudo chsh -s /bin/zsh
# 安装git
sudo apt install git

# 安装 oh-my-zsh
sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"
# 安装 Powerlevel10k主题
git clone https://github.com/romkatv/powerlevel10k.git $ZSH_CUSTOM/themes/powerlevel10k
vim ~/.zshrc 
# 写入 ZSH_THEME="powerlevel10k/powerlevel10k"
source ~/.zshrc

# 安装字体
# sudo apt install fonts-powerline
# 主题配置
p10k configure
```

安装ZSH插件：

```bash
# zsh-autosuggestions
git clone git://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
vim ~/.zshrc 
# 写入 plugins=(zsh-autosuggestions git)
source ~/.zshrc

# zsh-syntax-highlighting
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git $ZSH_CUSTOM/plugins/zsh-syntax-highlighting
echo "source $ZSH_CUSTOM/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh" >> ${ZDOTDIR:-$HOME}/.zshrc
source ~/.zshrc
```

安装Color LS：

```bash
sudo apt-add-repository ppa:brightbox/ruby-ng
sudo apt-get update
sudo apt-get install ruby2.5
sudo apt-get install ruby2.5-dev
sudo apt-get install build-essential libtool
sudo gem install colorls
vim ~/.zshrc
# 末尾追加 alias ls='colorls'
source ~/.zshrc
```

Windows Terminal配置：

```json
      {
        "guid": "{c6eaf9f4-32a7-5fdc-b5cf-066e8a4b1e40}",
        "hidden": false,
        "name": "Ubuntu-18.04",
        "source": "Windows.Terminal.Wsl",
        "backgroundImageStretchMode": "uniformToFill",
        "useAcrylic": true, //背景毛玻璃效果
        "acrylicOpacity": 0.7,
        "colorScheme": "One_Half_Dark",
        "fontFace": "Hack NF",
        "cursorShape": "filledBox", // 光标形状
        "closeOnExit": true, //关闭窗口的时候退出所有挂载的程序
        "cursorColor": "#FFFFFF" //光标颜色
      }
```

VS Code：

```
设置远程终端字体：文件 > 首选项 > 设置 > 搜索“终端” > Hack NF
```

## PowerShell终端

字体安装（Hack Nero Font）：

```
下载地址：https://github.com/ryanoasis/nerd-fonts/releases/download/v2.1.0/Hack.zip
```

安装Choco包管理器：

```powershell
# 管理员模式运行PowerShell
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
# 升级Choco
choco upgrade chocolatey
```

安装colortool：

```powershell
# 管理员模式运行PowerShell
choco.exe install colortool
# 查看已安装的colortool主题
ColorTool.exe -s
# 预览配色
ColorTool.exe cmd-legacy.ini
# 保存当前配色：powershell 顶部右键 -> 属性 -> 确定

# 更多配色：iterm2colorschemes
```

安装oh-my-posh：

```powershell
Install-Module posh-git -Scope CurrentUser
Install-Module oh-my-posh -Scope CurrentUser

# 查看主题
Get-PoshThemes

# 配置主题
if (!(Test-Path -Path $PROFILE )) { New-Item -Type File -Path $PROFILE -Force }
# 路径 C:\Users\<用户名>\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1
notepad $PROFILE
# 添加以下内容：
Import-Module posh-git
Import-Module oh-my-posh
Set-PoshPrompt -Theme negligible
```

