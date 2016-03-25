#include <fstream>
int main()
{
	std::ofstream file;
	file.open("file.txt");
	file<<"Hello file"<<std::endl;
	file.close();
}
