#include<thread> 
#include<bits/stdc++.h>

using namespace std;

class logFile{
	std::mutex m_mutex;
	ofstream f;
public:
	logFile(){
		f.open("input.in");
	}

	void share_print(string id, int value){
		std::lock_guard<mutex> locker(m_mutex);
		f << "From "<< id << ": " << value << endl;
	}
	// Never return f to the outside world
	// Never pass f as an argument to user provided function;
};

void function_l(logFile& log){
	for (int i = 0; i > -100; i--){
		log.share_print(string("From t1: "), i);
	}
}

int main(){
	logFile log; 
	std::thread t1(function_l, std::ref(log));
	for (int i = 0; i > -100; i--){
		log.share_print(string("From main: "), i);
	}
	t1.join();
	return 0;
}


