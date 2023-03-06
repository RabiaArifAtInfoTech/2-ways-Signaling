//// condition_variable example
//#include <iostream>           // std::cout
//#include <thread>             // std::thread
//#include <mutex>              // std::mutex, std::unique_lock
//#include <condition_variable> // std::condition_variable
//
//std::mutex mtx;
//std::condition_variable cv;
//bool ready = false;
//
//void print_id(int id) {
//    std::unique_lock<std::mutex> lck(mtx);
//    while (!ready) cv.wait(lck);
//    // ...
//    std::cout << "thread " << id << '\n';
//}
//
//void go() {
//    std::unique_lock<std::mutex> lck(mtx);
//    ready = true;
//    cv.notify_all();
//}
//
//int main()
//{
//    std::thread threads[10];
//    // spawn 10 threads:
//    for (int i = 0; i < 10; ++i)
//        threads[i] = std::thread(print_id, i);
//
//    std::cout << "10 threads ready to race...\n";
//    go();                       // go!
//
//    for (auto& th : threads) th.join();
//
//    return 0;
//}

#include<vector>
#include<iostream>
//#include<boost/signals2/signal.hpp>
#include<thread>
#include<mutex>
#include <condition_variable>
using namespace std;

std::mutex mtx;
std::condition_variable cv;
bool received = false;

//boost::signals2::signal<void(std::vector<std::string>)> signalMessages;
void Receiver(std::string msg);

void Sender(std::string msg) {

	std::unique_lock<std::mutex> lck(mtx);
	Receiver(msg);
	while (!received) {
		cv.wait(lck);
	}
	cout << "\nsignal received\n";

}

void Receiver(std::string msg) {
	cout << msg << " from reciever\n";
	received = true;
}

int main() 
{
	/*std::vector<std::string> messages;

	messages.push_back("Message 1");
	messages.push_back("Message 2");
	messages.push_back("Message 3");*/


	Sender("Message 1 sending");



	cout << "\n\n";
	return 0;
}