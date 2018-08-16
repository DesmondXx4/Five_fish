using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms; 

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }        

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        //public int[] pork = { 0, 0, 0, 0 };

        private void button17_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            Random rn1 = new Random();
            int[] pork = { 0, 0, 0, 0 };
            //pork[1] = rn1.Next(1,52);
            //int j = 0;
            //int i = 1;
            //int n = 0;
            //while (pork[3]==0)
            //{
            //    pork[i]=rn1.Next(1,52);
            //    for (j = 0; j <= i - 1; j++)
            //    {
            //        if (pork[j] != pork[i])
            //            n++;
            //    }
            //    if (n == j)
            //        i++;
            //}
            int k = 0;
            int i = 0;
            do {
                k = rn1.Next(1, 52);
                if (!pork.Contains(k))
                {
                    pork[i] = k;
                    i++;
                }
            } while (pork[3] == 0);


            string fname1 = "C:\\2\\WindowsFormsApp1\\WindowsFormsApp1\\Resources\\" + pork[0] + ".jpg";
            pictureBox1.Image = Image.FromFile(fname1);
            string fname2 = "C:\\2\\WindowsFormsApp1\\WindowsFormsApp1\\Resources\\" + pork[1] + ".jpg";
            pictureBox2.Image = Image.FromFile(fname2);
            string fname3 = "C:\\2\\WindowsFormsApp1\\WindowsFormsApp1\\Resources\\" + pork[2] + ".jpg";
            pictureBox3.Image = Image.FromFile(fname3);
            string fname4 = "C:\\2\\WindowsFormsApp1\\WindowsFormsApp1\\Resources\\" + pork[3] + ".jpg";
            pictureBox4.Image = Image.FromFile(fname4);


        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            textBox1.Text += "1";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text += "2";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text += "3";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text += "4";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text += "5";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox1.Text += "6";
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text += "7";
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text += "8";
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.Text += "9";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox1.Text += "(";
        }

        private void button11_Click(object sender, EventArgs e)
        {
            textBox1.Text += "0";
        }

        private void button12_Click(object sender, EventArgs e)
        {
            textBox1.Text += ")";
        }

        private void button13_Click(object sender, EventArgs e)
        {
            textBox1.Text += "+";
        }

        private void button14_Click(object sender, EventArgs e)
        {
            textBox1.Text += "-";
        }

        private void button15_Click(object sender, EventArgs e)
        {
            textBox1.Text += "*";
        }

        private void button16_Click(object sender, EventArgs e)
        {
            textBox1.Text += "/";
        }

        private void button19_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = true;
        }

        private void button18_Click(object sender, EventArgs e)
        {
            string ans = textBox1.Text;
            MSScriptControl.ScriptControl sc = new MSScriptControl.ScriptControlClass();
            sc.Language = "JavaScript";
            var b = sc.Eval(ans);
            //string a1 = pork[0].ToString();
            //string a2 = pork[1].ToString();
            //string a3 = pork[2].ToString();
            //string a4 = pork[3].ToString();
            string end = b.ToString();
            if (end == "24")
                 textBox1.Text = "结果是24，答案正确，恭喜你！";
            else
                 textBox1.Text = "结果不是24，回答错误，请开始新游戏！";
            
        }
    }
}
