#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	bitset<16> bs(0xffff);
	bs[10]=0;
	for( int i = (int) bs.size()-1; i >= 0; i-- ) {
		cout << bs[i] << " ";
	}
	cout << endl;
	cout << bs.count()<<endl;
	bs.flip();
	for( int i = (int) bs.size()-1; i >= 0; i-- ) {
		cout << bs[i] << " ";
	}
	cout << endl;
	cout << bs.to_string()<<endl;
	return 0;



}
