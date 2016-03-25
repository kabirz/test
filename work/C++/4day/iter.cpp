#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> aa;//(10,"Hello");
	aa.push_back("Hello,world");
	for(vector<string>::const_iterator iter = aa.begin();iter!= aa.end();iter ++)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
