#include<iostream> 
#include<iomanip>
#include<cstring> 
using namespace std;
class playtime
{ 
  int hour,minute;
  public:
  playtime(int Hour=0,int Minute=0)
  {hour=Hour;minute=Minute;}//构造函数，给出初始时间 
  void settime(int Hour,int Minute) 
  {hour=Hour;minute=Minute;}//设置时间
  int get_hour() {return hour;}//获取小时
  int get_minute() {return minute;}  //获取分钟
};

class card
{ public:
  int ground;    //场地编号 
  playtime borrow_time;  //出借时间
  playtime return_time; //归还时间
  int expiry; //借用时间
  int money;   //标准收费
  //card() {};//构造函数 
  card(int Ground,playtime Borrow_time,playtime Return_time)  
  {ground=Ground;borrow_time=Borrow_time;return_time=Return_time;}
  playtime get_borrow_time() 
  {return borrow_time;} //获取出借时间 
  playtime get_return_time()
  {return return_time;}//获取归还时间
  int get_ground() {return ground;}   //获取场地编号  
  int get_expiry();//获取借用时间
  int get_money();
};

int card::get_expiry()
{ int hb,mb,hr,mr;
  hb=borrow_time.get_hour();
  mb=borrow_time.get_minute();
  hr=return_time.get_hour();
  mr=return_time.get_minute();
  expiry=(hr-hb)*60+(mr-mb);
  return expiry;
 }  

int card::get_money() 
{ int hb,mb,hr,mr;
  hb=borrow_time.get_hour();
  mb=borrow_time.get_minute();
  hr=return_time.get_hour();
  mr=return_time.get_minute();
  expiry=(hr-hb)*60+(mr-mb);
  if(expiry<=60) {money=50;}
  else {money=expiry/60*50;}
  return money;}

class Teacher: public card//老师
{ public:
  char teaNo[30];
  Teacher(char TeaNo[],int Gro,playtime Borrowt,playtime Returnt): card(Gro,Borrowt,Returnt)
  {strcpy(teaNo,TeaNo);}
  void get_No() {cout<<teaNo;}
};
class Student: public card//学生
{ public:
  char stuNo[30];
  Student(char StuNo[],int Gro,playtime Borrowt,playtime Returnt): card(Gro,Borrowt,Returnt)
  {strcpy(stuNo,StuNo);}
  void get_No() {cout<<stuNo;}
  
};
class Outschool:public card//校外人员
{ public:
  char name[30];
  Outschool(char Name[],int Gro,playtime Borrowt,playtime Returnt): card(Gro,Borrowt,Returnt)
  {strcpy(name,Name);}
  void get_No() {cout<<name;}
};

int main() 
{playtime bt(14,30),rt(16,40);
 Teacher t("T19950103",3,bt,rt);
 Student s("U20165534",3,bt,rt);
 Outschool o("张三",3,bt,rt);
 card c(3,bt,rt);
 //以下打印老师发票信息 
 cout<<"老师发票: "<<endl; 
 cout<<"-------------------------------------------------"<<endl; 
 cout<<setw(10)<<'*'<<"场地编号: "<<t.get_ground()<<endl; 
 cout<<setw(10)<<'*'<<"借用者: ";
 t.get_No();
 cout<<endl;  
 cout<<setw(10)<<'*'<<"出借时间: "<<bt.get_hour()<<":"<<bt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"归还时间: "<<rt.get_hour()<<":"<<rt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"借用时间: "<<t.get_expiry()<<endl;
 cout<<setw(10)<<'*'<<"租金: "<<(t.get_money())*0.8<<endl;
 cout<<"--------------------------------------------------"<<endl; 
 //以下打印学生发票信息 
 cout<<"学生发票: "<<endl; 
 cout<<"-------------------------------------------------"<<endl; 
 cout<<setw(10)<<'*'<<"场地编号: "<<s.get_ground()<<endl; 
 cout<<setw(10)<<'*'<<"借用者: ";
 s.get_No();
 cout<<endl;  
 cout<<setw(10)<<'*'<<"出借时间: "<<bt.get_hour()<<":"<<bt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"归还时间: "<<rt.get_hour()<<":"<<rt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"借用时间: "<<s.get_expiry()<<endl;
 cout<<setw(10)<<'*'<<"租金: "<<(s.get_money())*0.2<<endl;
 cout<<"--------------------------------------------------"<<endl; 
 //以下打印校外人员发票信息 
 cout<<"校外人员发票: "<<endl; 
 cout<<"-------------------------------------------------"<<endl; 
 cout<<setw(10)<<'*'<<"场地编号: "<<o.get_ground()<<endl; 
 cout<<setw(10)<<'*'<<"借用者: ";
 o.get_No();
 cout<<endl;  
 cout<<setw(10)<<'*'<<"出借时间: "<<bt.get_hour()<<":"<<bt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"归还时间: "<<rt.get_hour()<<":"<<rt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"借用时间: "<<o.get_expiry()<<endl;
 cout<<setw(10)<<'*'<<"租金"<<o.get_money()<<endl;
 cout<<"--------------------------------------------------"<<endl;
 
return 0;
}