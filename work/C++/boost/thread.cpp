#include <boost/thread/thread.hpp>
#include <iostream>
 
using namespace std; 
 
void hello_world() 
{
  cout << "Hello world, I'm a thread!" << endl;
}
 
int main(int argc, char* argv[])
{
  // 開始一條使用 "hello_world" function 的新執行緒
  boost::thread my_thread(&hello_world);
  // 等待執行緒完成工作
  my_thread.join();
 
  return 0;
}
