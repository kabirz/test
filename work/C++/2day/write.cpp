#include <fstream>
int main()
{
	std::fstream file;
	file.open("file.txt",std::ios::in|std::ios::out|std::ios::ate);
	file<<"Hello file"<<std::endl;
	file<<"Hello file"<<std::endl;
	file.close();
}
