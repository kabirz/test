#include <iostream>
using namespace std;
int main( )
{
	int max(int a,int b,int c); //函数声明
	int max(int a,int b); //函数声明
	int a=8,b=-12,c=27;
	cout<<"max(a,b,c)="<<max(a,b,c)<<endl;//输出 3 个整数中的最大者
	cout<<"max(a,b)="<<max(a,b)<<endl; //输出两个整数中的最大者
}
int max(int a,int b,int c)//此 max 函数的作用是求 3 个整数中的最大者
{
	if(b>a) a=b;
	if(c>a) a=c;
	return a;
}
int max(int a,int b)//此 max 函数的作用是求两个整数中的最大者
{
	if(a>b) return a;
	else return b;
}

