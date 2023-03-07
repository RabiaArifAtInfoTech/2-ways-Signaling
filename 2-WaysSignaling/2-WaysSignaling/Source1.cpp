//#include<vector>
//#include<iostream>
////#include<boost/signals2/signal.hpp>
//#include<thread>
//#include<mutex>
//#include <condition_variable>
//using namespace std;
//
//std::mutex mtx;
//std::condition_variable cv;
//bool received = false;
//
//void Receiver(std::string msg);
//
//void Sender(std::vector<std::string> messages) {
//
//	std::unique_lock<std::mutex> lck(mtx);
//	
//	for (int i = 0; i < messages.size(); i++)
//	{
//		Receiver(messages[i]);
//		cv.wait(lck);
//
//		while (!received) {
//			cout << "\nin while before " << i <<"\n";
//			cv.wait(lck);
//			cout << "\nin while after "<< i <<"\n";
//		}
//		cout << "\nSignal " << i + 1 << " received from Receiver \n";
//		received = false;
//	}
//
//}
//
//void Receiver(std::string msg) {
//	cout << "\n" << msg << " received to Receiver\n";
//	received = true;
//}
//
//int main()
//{
//	std::vector<std::string> messages;
//
//	messages.push_back("Message 1");
//	messages.push_back("Message 2");
//	messages.push_back("Message 3");
//	messages.push_back("Message 4");
//	messages.push_back("Message 5");
//	messages.push_back("Message 6");
//
//
//	Sender(messages);
//
//
//
//	cout << "\n\n";
//	return 0;
//}