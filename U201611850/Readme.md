# 吴心怡的Demo--贪食蛇
## Demo简介
本demo是基于Visual C++的一款简易版贪食蛇游戏
## 玩法介绍
wsad控制蛇

*为蛇，$为食物

每碰到食物则增加节数

空格键暂停
## 程序代码
 

#include <iostream>

#include<conio.h>

#include<time.h>

#include<windows.h>

#define X 15


#define Y 15

int score=0;

char ch[X][Y];

char lch = 's';

char nch = 's';

class Snake

{

public:

Snake() { nx = 8;ny = 8;lx = 9;ly = 9;next = 
NULL; }

Snake(Snake&r);//建立蛇身

void input();//把数据输入到图像

void control();//控制贪吃蛇

void show();//显示图像

void check();//检测食物是否被吃掉

bool gameover();//检测游戏是否结束

int nx;

int ny;

int lx;

int ly;

Snake*next;

};

Snake *head;

namespace Food

{

int x;

int y;

void NEW()

{

Snake*p=head;

x = rand() % X;

y = rand() % Y;

while(p!=NULL)

{

if(p->nx==x&&p->ny==y)

{

x = rand() % X;

y = rand() % Y;

p = head;

}

else

p=p->next;

}

ch[x][y]='$';

}

};

Snake::Snake(Snake&r)

{

this->nx = r.lx;

this->ny = r.ly;

r.next = this;

this->next = NULL;

}

void Snake::show()//显示图像

{

system("cls");

//std::cout << " 
------------------------------ \n";

for (int y = 0; y<Y; ++y)

{

//std::cout << "|";

for (int x = 0; x < X; ++x)

std::cerr << ch[x][y] << " " ;

std::cerr <<"|"<< std::endl;

}

std::cout << " ------------------------------ 
\n";

printf("x = %d,y = %d\n",nx,ny);

printf("x = %0X,y = %0X\n",&nx,&ny);

printf("score = %d\n",score);

}

void Snake::control()//键盘控制

{

if (_kbhit() == 1)

{

nch = _getch();

lx = nx;

ly = ny;

if (nch == 'w' || nch == 's' || nch == 'a' || 
nch == 'd')

{

lch = nch;

switch (nch)

{

case 'w':if (ny == 0) ny = Y - 1; else --ny; 
break;

case 's':if (ny == Y - 1) ny = 0; else ++ny; 
break;

case 'a':if (nx == 0) nx = X - 1; else --nx; 
break;

case 'd':if (nx == X - 1) nx = 0; else ++nx; 
break;

}

}

else

{

switch (lch)

{

case 'w':if (ny == 0) ny = Y - 1; else --ny; 
break;

case 's':if (ny == Y - 1) ny = 0; else ++ny; 
break;

case 'a':if (nx == 0) nx = X - 1; else --nx; 
break;

case 'd':if (nx == X - 1) nx = 0; else ++nx; 
break;

}

}

}

else

{

lx = nx;

ly = ny;

if (nch == 'w' || nch == 's' || nch == 'a' || 
nch == 'd')

{

lch = nch;

switch (nch)

{

case 'w':if (ny == 0) ny = Y - 1; else --ny; 
break;

case 's':if (ny == Y - 1) ny = 0; else ++ny; 
break;

case 'a':if (nx == 0) nx = X - 1; else --nx; 
break;

case 'd':if (nx == X - 1) nx = 0; else ++nx; 
break;

}

}

else

{

switch (lch)

{

case 'w':if (ny == 0) ny = Y - 1; else --ny; 
break;

case 's':if (ny == Y - 1) ny = 0; else ++ny; 
break;

case 'a':if (nx == 0) nx = X - 1; else --nx; 
break;

case 'd':if (nx == X - 1) nx = 0; else ++nx; 
break;

}

}

}

}

void Snake::input()//把对象输入到图像

{

Snake*p = head;

ch[p->lx][p->ly] = ' ';

ch[p->nx][p->ny] = '*';

while (p->next != NULL)

{

p->next->lx = p->next->nx;

p->next->ly = p->next->ny;

p->next->nx = p->lx;

p->next->ny = p->ly;

p = p->next;

ch[p->lx][p->ly] = ' ';

ch[p->nx][p->ny] = '*';

}

}

void Snake::check()//检测食物是否被吃掉

{

Snake*p=head;

if (p->nx == Food::x&&p->ny == Food::y)

{

Snake*p = head;

while (p->next != NULL)

{

p = p->next;

}

p->next = new Snake(*p);

Food::NEW();

++score;

}

}

bool Snake::gameover()//检测游戏是否结束

{

Snake*p = head;

Snake*pn = head->next;

while (p != NULL)

{

while (pn != NULL)

{

if (p->nx == pn->nx&&p->ny == pn->ny)

{

std::cout << "Game Over\n";

return true;

}

pn = pn->next;

}

p = p->next;

}

return 0;

}

int main()

{

//初始化

srand(time(NULL));

for (int y = 0; y<Y; ++y)

for (int x = 0; x<X; ++x)

ch[x][y] = ' ';

head = new Snake;

Food::NEW();

std::cout<<"游戏规则:\n1.wsad(小写)控制蛇\n2.若
蛇节数超过2，那么无法反方向运动，\n若反方向运动则
GameOver\n3.'*'为蛇,'$'为食物\n";

system("pause");

//开始游戏

while (1)

{

head->control();

head->input();

head->check();

if(head->gameover())

break;

head->show();

Sleep(100);
}


Sleep(1000);

system("pause");
return 0;


}



