#define LOG_TAG "MyThread"   

#include <utils/Log.h>   
#include <utils/threads.h>   
using namespace android;  

class MyThread: public Thread {  
	public:  
		MyThread() {  
			LOGD("MyThread");  
		};  

		virtual ~MyThread(){  
			LOGD("~MyThread");  
		};  

		bool threadLoop(){  
			LOGD("threadLoop");  
			return true;  
		};  

};  

int main(){  
	LOGD("main start");  
	sp<MyThread> th = new MyThread();
	th->run();  
	while(1)usleep(100);  
	LOGD("main end");  
	return 0;  
}  

