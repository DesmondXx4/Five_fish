# DEMO INSTRUCTION
## 对于程序Calculator的简介
    该程序是借助Visual Studio 2017中C#Windows窗体应用来建立一个简易的计算器，包括加减乘除和清零功能。利用其中的button和textbox控件来完成主界面。
* 开发环境：Visual Studio 2017
* 编程语言：C#
***
## 主界面
![Calculator主界面](Calculator主界面.png "Calculator主界面")
***
## 程序代码
### 添加addNum函数
```c
public void addNum(int num)
        {
            textBox1.Text = textBox1.Text + num.ToString();
        }
```
### 利用addNum函数在显示屏中添加数字
```c
//7
        private void button1_Click(object sender, EventArgs e)
        {
            addNum(7);//在显示屏中添加数字7         
        }
```
### 修改运算方式变量
```c
 //除法
        private void button12_Click(object sender,EventArgs e)
        {
            cal = 4;//修改运算标志
            temp1 = Convert.ToInt64(textBox1.Text);//将第一个数设置为前一个数值
            textBox1.Clear();
        }
```       
### 等于号输出结果
```c
//利用switch语句判断运算方式变量
//利用if语句排除除数为0的情况
case 4:
                    if (temp2 == 0)
                    {
                        textBox1.Text = "0不能为除数！请清零后重新输入";
                    }
                    else
                    {
                        textBox1.Text = (temp1 / temp2).ToString();
                    }
                    break;
```
### 归零功能的实现
```c
//归零
        private void button11_Click(object sender,EventArgs e)
        {
            textBox1.Text = "";//显示屏清零
            temp1 = 0;//第一个数清零
            cal = 0;//运算标志清零
        }                   
```
 
***
* 开发者：电气1608班徐圣博
* 开发者联系方式：499853893@qq.com