# Five_fish
---
# Readme document for Demo1 
# 欢迎阅读2048Demo的说明文档

---
### 简介  

这是一个暑期工程实习的实例**Demo**，2048小游戏是这个**Demo**的实现的实际功能。接下来我将对这个**Demo**的相关内容进行说明：

> * 本**Demo**基于CSDN的一位博主的相关思路
> * 图片资源来自互联网
> * 仅作相关学习使用，不得用作商业用途
> * 请在下载后24小时内删除  
  
  

![2048的logo](pic/2048.jpg)
  
    
    
### [Windows程序下载](https://github.com/DesmondXx4/Five_fish/blob/master/Demo1/Debug/Cpp1.exe)


------

## 1.什么是 2048

《2048》，是一款益智小游戏，这款游戏是由年仅19岁的意大利程序员加布里勒希鲁尼（Gabriele Cirulli）开发出来的，官方版本只能在网页上或通过其移动网站运行。

### 2. 本**Demo**的编译环境

- [x] Visual C++ 6.0（都8102年了还有人用这么落后的IDE）
- [x] Graphics.h 库文件（需要下载EasyX图形库）

### 3.2048怎么玩

2048游戏共有16个格子，初始时会有两个格子上安放了两个数字2，每次可以选择上下左右其中一个方向去滑动，每滑动一次，所有的数字方块都会往滑动的方向靠拢外，系统也会在空白的地方随即出现一个数字方块，相同数字的方块在靠拢、相撞时会相加。系统给予的数字方块不是2就是4，玩家要想办法在这小小的16格范围中凑出“2048”这个数字方块。

### 4.新手攻略：

2048这类以数字游戏为原型的游戏是肯定有规律的，新手玩家们不要随意乱移，这款游戏最佳的模式是按照升序或者降序的方式来排列合并，最左上角是最大的格子，其次是次大的，按序列递减，这样的排列效率较高，且省去一些麻烦的思考与计算。

那么我们再来看看如果是自己肆意排列会产生什么样的效果（如下图），在自己随意移动，排列无序的情况下，很容易出现最大数格子位置不稳定，而周围同样的格子也很分散，难以使用，成为白白占用空间而无作用的格子。下图中显示，这样移动一下64在中间，2在左下角，周围的要合并的16，8也难以凑到一起。于是就要另外再合过16，8来合并，这样又造成不必要的浪费。  
  
    
    
![sample](https://gss0.baidu.com/-Po3dSag_xI4khGko9WTAnF6hhy/zhidao/pic/item/d8f9d72a6059252d6f58a3fe3f9b033b5ab5b9f9.jpg)

### 5. 本Demo操作方式
左移：A键/方向键←  
右移：D键/方向键→  
上移：W键/方向键↑  
下移：S键/方向键↓  
按ESC返回主界面  


```c++
void interact()
{
	char keyboard;
	keyboard = _getch();
	if (keyboard == 'w' || keyboard == 'W' || keyboard == 72)interact_up();//上
	if (keyboard == 's' || keyboard == 'S' || keyboard == 80)interact_down();//下
	if (keyboard == 'a' || keyboard == 'A' || keyboard == 75)interact_left();//左
	if (keyboard == 'd' || keyboard == 'D' || keyboard == 77)interact_right();//右
	if (keyboard == 27)//esc主菜单
	{
		flag = 0;
		setbkcolor(RGB(251, 248, 241));
		start_4();
	}
}
```
> \*请保留此份本**Demo**的欢迎稿兼使用说明，如需提交Bug或相关建议，点击上方工具栏左边侧的**Issues**进行提交

---
玩的开心：）
---

