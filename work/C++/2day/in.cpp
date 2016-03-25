#include <fstream>
#include <iostream>
int main()
{
	std::ifstream file;
	char output[100]={0};
	int x;
	file.open("file.txt");
	file>>output;
	std::cout<<output<<std::endl;
	file.close();
}
