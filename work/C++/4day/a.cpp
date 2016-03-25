#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char ch;
	ifstream fin("temp.txt");
	int i = 0;
#if 0
	while(!fin.eof()){
		fin>>ch;
		cout<<ch;
		i++;
	}
	cout<<endl;
#else
	while(fin.get(ch)){
			cout<<ch;
	}
#endif
	fin.close();
}
