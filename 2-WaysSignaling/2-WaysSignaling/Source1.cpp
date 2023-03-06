#include<vector>
#include<iostream>
#include<boost/signals2/signal.hpp>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mute;

boost::signals2::signal<void(std::vector<std::string>)> signalMessages;


void Sender(std::vector<std::string> msgs) {




}

void Receiver() {

}

int main() 
{
	std::vector<std::string> messages;

	messages.push_back("Message 1");
	messages.push_back("Message 2");
	messages.push_back("Message 3");

	Sender(messages);



	cout << "\n\n";
	return 0;
}