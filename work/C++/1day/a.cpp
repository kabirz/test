#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int m, k, i, n = 0;
	bool prime;			//定义布尔变量 prime
	int *a = new int;
	for (m = 101; m <= 200; m = m + 2)	//判别 m 是否为素数,m 由 101 变化到 200,增量为2
		{
			prime = true;		//循环开始时设 prime 为真,即先认为 m 为素数
			k = int (sqrt (m));	//用 k 代表根号 m 的整数部分
			for (i = 2; i <= k; i++)	//此循环作用是将 m 被 2~根号 m 除,检查是否能整除
				if (m % i == 0)		//如果能整除,表示 m 不是素数
				{
					prime = false;	//使 prime 变为假
					break;		//终止执行本循环
				}
			if (prime)		//如果 m 为素数
			{
				cout << setw (5) << m;	//输出素数 m,字段宽度为 5
				n = n + 1;		//n 用来累计输出素数的个数
			}
			if (n % 10 == 0)
				cout << endl;		//输出 10 个数后换行
		}
	cout << endl;			//最后执行一次换行
	return 0;
}
