#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	ofstream file("temp.txt",ios::app);
	file<<"Hello,sb"<<endl;
	file.close();
	return 0;
}
