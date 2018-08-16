#include<iostream> 
#include<iomanip>
#include<cstring> 
using namespace std;
class playtime
{ 
  int hour,minute;
  public:
  playtime(int Hour=0,int Minute=0)
  {hour=Hour;minute=Minute;}//���캯����������ʼʱ�� 
  void settime(int Hour,int Minute) 
  {hour=Hour;minute=Minute;}//����ʱ��
  int get_hour() {return hour;}//��ȡСʱ
  int get_minute() {return minute;}  //��ȡ����
};

class card
{ public:
  int ground;    //���ر�� 
  playtime borrow_time;  //����ʱ��
  playtime return_time; //�黹ʱ��
  int expiry; //����ʱ��
  int money;   //��׼�շ�
  //card() {};//���캯�� 
  card(int Ground,playtime Borrow_time,playtime Return_time)  
  {ground=Ground;borrow_time=Borrow_time;return_time=Return_time;}
  playtime get_borrow_time() 
  {return borrow_time;} //��ȡ����ʱ�� 
  playtime get_return_time()
  {return return_time;}//��ȡ�黹ʱ��
  int get_ground() {return ground;}   //��ȡ���ر��  
  int get_expiry();//��ȡ����ʱ��
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

class Teacher: public card//��ʦ
{ public:
  char teaNo[30];
  Teacher(char TeaNo[],int Gro,playtime Borrowt,playtime Returnt): card(Gro,Borrowt,Returnt)
  {strcpy(teaNo,TeaNo);}
  void get_No() {cout<<teaNo;}
};
class Student: public card//ѧ��
{ public:
  char stuNo[30];
  Student(char StuNo[],int Gro,playtime Borrowt,playtime Returnt): card(Gro,Borrowt,Returnt)
  {strcpy(stuNo,StuNo);}
  void get_No() {cout<<stuNo;}
  
};
class Outschool:public card//У����Ա
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
 Outschool o("����",3,bt,rt);
 card c(3,bt,rt);
 //���´�ӡ��ʦ��Ʊ��Ϣ 
 cout<<"��ʦ��Ʊ: "<<endl; 
 cout<<"-------------------------------------------------"<<endl; 
 cout<<setw(10)<<'*'<<"���ر��: "<<t.get_ground()<<endl; 
 cout<<setw(10)<<'*'<<"������: ";
 t.get_No();
 cout<<endl;  
 cout<<setw(10)<<'*'<<"����ʱ��: "<<bt.get_hour()<<":"<<bt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"�黹ʱ��: "<<rt.get_hour()<<":"<<rt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"����ʱ��: "<<t.get_expiry()<<endl;
 cout<<setw(10)<<'*'<<"���: "<<(t.get_money())*0.8<<endl;
 cout<<"--------------------------------------------------"<<endl; 
 //���´�ӡѧ����Ʊ��Ϣ 
 cout<<"ѧ����Ʊ: "<<endl; 
 cout<<"-------------------------------------------------"<<endl; 
 cout<<setw(10)<<'*'<<"���ر��: "<<s.get_ground()<<endl; 
 cout<<setw(10)<<'*'<<"������: ";
 s.get_No();
 cout<<endl;  
 cout<<setw(10)<<'*'<<"����ʱ��: "<<bt.get_hour()<<":"<<bt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"�黹ʱ��: "<<rt.get_hour()<<":"<<rt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"����ʱ��: "<<s.get_expiry()<<endl;
 cout<<setw(10)<<'*'<<"���: "<<(s.get_money())*0.2<<endl;
 cout<<"--------------------------------------------------"<<endl; 
 //���´�ӡУ����Ա��Ʊ��Ϣ 
 cout<<"У����Ա��Ʊ: "<<endl; 
 cout<<"-------------------------------------------------"<<endl; 
 cout<<setw(10)<<'*'<<"���ر��: "<<o.get_ground()<<endl; 
 cout<<setw(10)<<'*'<<"������: ";
 o.get_No();
 cout<<endl;  
 cout<<setw(10)<<'*'<<"����ʱ��: "<<bt.get_hour()<<":"<<bt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"�黹ʱ��: "<<rt.get_hour()<<":"<<rt.get_minute()<<endl; 
 cout<<setw(10)<<'*'<<"����ʱ��: "<<o.get_expiry()<<endl;
 cout<<setw(10)<<'*'<<"���"<<o.get_money()<<endl;
 cout<<"--------------------------------------------------"<<endl;
 
return 0;
}