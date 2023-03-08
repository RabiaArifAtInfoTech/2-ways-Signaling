#include<vector>
#include<iostream>
//#include<boost/signals2/signal.hpp>
#include<thread>
#include<mutex>
#include <condition_variable>
#include<boost/thread/condition.hpp>
#include<boost/interprocess/sync/scoped_lock.hpp>

//#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>


boost::mutex mtx;
boost::condition_variable cndSignal;


void f2(int n);
void f1() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = sum + i;
		std::cout << "\nin f1 for " << i + 1 <<"\n";
		/*cndSignal.notify_one();
		f2(sum);*/
	}
	cndSignal.notify_one();
	
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "\nafter notify \n";
}

void f2(int num) {
	
	int square = 0;
	boost::mutex::scoped_lock mtxWait(mtx);
	cndSignal.wait(mtxWait);
	std::cout << "\nSignal Recieved in f2\n";
	square = num * num;
	std::cout << "\nSquare of " << num << " is " << square <<  "\n";
}

int main() {

	std::thread Thread1(f1);
	std::thread Thread2(f2,5);
	Thread1.join();
	Thread2.join();
	return 0;
}

//boost::condition& cndSignal()
//{
//	// TODO: insert return statement here
//	cout << "\ninside cndSignal Return Statement\n";
//}