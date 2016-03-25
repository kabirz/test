#include <iostream>
using namespace std;
class Date;			//对Date类的提前引用声明
class Time			//定义Time类
{
  public:Time (int, int, int);
  void display (Date &);	//display是成员函数,形参是Date类对象的引用
    private:int hour;
  int minute;
  int sec;
};
class Date			//声明Date类
{
  public:Date (int, int, int);
  friend void Time::display (Date &);	//声明Time中的display函数为友元成员函数
    private:int month;
  int day;
  int year;
};
Time::Time(int h,int m,int s)
{
	hour = h;
	minute = m;
	sec = s;
}
void
Time::display (Date & d)
{
  cout << d.month << "/" << d.day << "/" << d.year << endl;	//引用Date类对象中的私有数据
  cout << hour << ":" << minute << ":" << sec << endl;	//引用本类对象中的私有数据
}

Date::Date (int m, int d, int y)	//类Date的构造函数
{
  month = m;
  day = d;
  year = y;
}

int
main ()
{
  Time t1 (10, 13, 56);		//定义Time类对象t1
  Date d1 (12, 25, 2004);	//定义Date类对象d1
  t1.display (d1);
  //调用t1中的display函数,实参是Date类对象d1 ret
  return 0;
}
