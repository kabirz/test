#include <boost/array.hpp>
#include <iostream>
using namespace std;
void test_array()
{
	using boost::array;
	array<int,10> ai = {1,2,3}; 
	for(size_t i=0;i<ai.size();++i)
	{ 
		cout<<ai[i]<<endl; 
	}
}

int main()
{
	test_array();
	return 0;
}
