using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        float temp1 = 0;//记录第一个数字
        int cal = 0;//运算标志
        public void addNum(int num)
        {
            textBox1.Text = textBox1.Text + num.ToString();
        }
        //7
        private void button1_Click(object sender, EventArgs e)
        {
            addNum(7);//在显示屏中添加数字7         
        }
        //8
        private void button2_Click(object sender, EventArgs e)
        {
            addNum(8);//在显示屏中添加数字8
        }
        //9
        private void button3_Click(object sender, EventArgs e)
        {
            addNum(9);//在显示屏中添加数字9
        }
        //4
        private void button4_Click(object sender, EventArgs e)
        {
            addNum(4);//在显示屏中添加数字4
        }
        //5
        private void button5_Click(object sender, EventArgs e)
        {
            addNum(5);//在显示屏中添加数字5
        }
        //6
        private void button6_Click(object sender, EventArgs e)
        {
            addNum(6);//在显示屏中添加数字6
        }
        //1
        private void button7_Click(object sender, EventArgs e)
        {
            addNum(1);//在显示屏中添加数字1
        }
        //2
        private void button8_Click(object sender, EventArgs e)
        {
            addNum(2);//在显示屏中添加数字2
        }
        //3
        private void button9_Click(object sender, EventArgs e)
        {
            addNum(3);//在显示屏中添加数字3
        }
        //0
        private void button10_Click(object sender, EventArgs e)
        {
            addNum(0);//在显示屏中添加数字0
        }
        //除法
        private void button12_Click(object sender,EventArgs e)
        {
            cal = 4;//修改运算标志
            temp1 = Convert.ToInt64(textBox1.Text);//将第一个数设置为前一个数值
            textBox1.Clear();
        }
        //乘法
        private void button13_Click(object sender, EventArgs e)
        {
            cal = 3;//修改运算标志
            temp1 = Convert.ToInt64(textBox1.Text);//将第一个数设置为前一个数值
            textBox1.Clear();
        }
        //减法
        private void button14_Click(object sender, EventArgs e)
        {
            cal = 2;//修改运算标志
            temp1 = Convert.ToInt64(textBox1.Text);//将第一个数设置为前一个数值
            textBox1.Clear();
        }
        //加法
        private void button15_Click(object sender, EventArgs e)
        {
            cal = 1;//修改运算标志
            temp1 = Convert.ToInt64(textBox1.Text);//将第一个数设置为前一个数值
            textBox1.Clear();
        }
        //等于
        private void button16_Click(object sender,EventArgs e)
        {
            float temp2 = Convert.ToInt64(textBox1.Text);//赋予变量temp2第二个数的值
            switch(cal)//根据cal的值判断计算方法
            {
                case 1:
                    textBox1.Text = (temp1 + temp2).ToString();
                    break;
                case 2:
                    textBox1.Text = (temp1 - temp2).ToString();
                    break;
                case 3:
                    textBox1.Text = (temp1 * temp2).ToString();
                    break;
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
            }
        }
        //归零
        private void button11_Click(object sender,EventArgs e)
        {
            textBox1.Text = "";//显示屏清零
            temp1 = 0;//第一个数清零
            cal = 0;//运算标志清零
        }

        
    }
}
