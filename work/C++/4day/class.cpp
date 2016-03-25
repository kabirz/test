#include <iostream>
using namespace std;
class test {
	public:
	test()
	{
		cout<<"Hello"<<endl;
	}
	int a;
};

int main()
{
	test *a = new test();
	return 0;
}
