#include <boost/thread/thread.hpp>
#include <iostream>
 
using namespace std; 
 
void hello_world() 
{
  cout << "Hello world, I'm a thread!" << endl;
}
 
int main(int argc, char* argv[])
{
  // �_ʼһ�lʹ�� "hello_world" function �����оw
  boost::thread my_thread(&hello_world);
  // �ȴ����оw��ɹ���
  my_thread.join();
 
  return 0;
}
