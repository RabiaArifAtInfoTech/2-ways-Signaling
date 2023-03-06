//#include<vector>
//#include<iostream>
//#include<boost/signals2/signal.hpp>
//#include<thread>
//#include<mutex>
//using namespace std;
//
//std::mutex mute;
//
//class Reciver;
//
//class Sender {
//
//	std::vector<std::string> message;
//	boost::signals2::signal<void(std::vector<std::string>)> signalMessages;
//
//public:
//	Sender(std::vector<std::string> msgs) {
//		cout << "\ninside Sender class\n";
//		message = msgs;
//		for (int i = 0; i < msgs.size(); i++)
//			message.push_back(msgs[i]);
//		
//
//		int initialSize = message.size();
//		int tempSize = message.size();
//
//		cout << message[0];
//		signalMessages.connect(message[0]);
//		/*if (tempSize == initialSize)
//		{
//
//		}*/
//	}
//	void send()
//	{
//		int initialSize = message.size();
//		int tempSize = message.size();
//
//		//if()
//	}
//	void wait() {
//
//	}
//	void signal() {
//
//	}
//};
//
////class Receiver {
////	//std::thread t2();
////	boost::signals2::signal<string()> signal2;
////	std::vector<std::string> message;
////	int countOfReceivedMsgs;
////public:
////	Receiver() {
////
////	}
////	void receive(std::string msg) {
////		message.push_back(msg);
////		countOfReceivedMsgs++;
////		this->signal();
////	}
////	void run()
////	{
////		//std::thread t1();
////	}
////	void wait() {
////
////	}
////	void signal() {
////
////	}
////	void display(){
////	}
////};
//
////void thread2() {
////	//.std::thread t2();
////	boost::signals2::signal<void()> signal2;
////}
//
//int main()
//{
//
//	std::vector<std::string> messages;
//
//	messages.push_back("Message 1");
//	messages.push_back("Message 2");
//	messages.push_back("Message 3");
//
//	//Receiver R1;
//	Sender S1(messages);
//	
//	
//	//Receiver T2(response);
//
//	std::cout << "\n\n";
//	return 0;
//}