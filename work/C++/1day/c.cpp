#include <iostream>
using namespace std;
void printstar(void) //定义 printstar 函数
{
	cout<<"******************************"<<endl; //输出 30 个“*”
}
void print_message(void) //定义 print_message 函数
{
	cout<<"Welcome to C++!"<<endl; //输出一行文字
}
int main(void)
{
	printstar( ); //调用 printstar 函数
	print_message( ); //调用 print_message 函数
	printstar( ); //调用 printstar 函数
	return 0;
}
