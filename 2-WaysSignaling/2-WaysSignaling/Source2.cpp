//#include<iostream>
//#include<boost/signals2/signal.hpp>
//#include<thread>
//#include<mutex>
//
//boost::signals2::signal<void(int)> s;
//boost::signals2::signal<void(int)> ak;
//std::mutex mtx;
//
//int square(int sum);
//
//void thread1()
//{
//	int sum = 0;
//	std::cout << "\nThread One Function " << std::endl;
//	for (int i = 0; i <= 10; i++)
//	{
//		sum += i;
//		std::cout << i << "\t";
//	}
//	std::cout << std::endl;
//	std::cout << "\n" << sum << " sum value in thread 1 " << std::endl;
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//	s(sum);     
//	ak.connect([](int recivedSignalNumber) {
//		std::cout << "Recived Signal Number " << recivedSignalNumber << std::endl;
//		if (recivedSignalNumber == 11)
//		{
//			std::cout << "\nSignal is recived in Thread 2 function " << std::endl;
//		}
//		else {
//			//Not recived send again
//			std::cout << "\nsending Data again " << std::endl;
//		}
//	})
//}
//void thread2()
//{
//	std::cout << "\nThread Two Function " << std::endl;
//	for (int j = 0; j <= 10; j++)
//	{
//		std::cout << "j=" << j << "\t";
//	}     
//	s.connect([](int sum)
//		{
//			if (sum != 0)
//			{
//				std::cout << "\nAK Trigred" << std::endl;
//				//std::this_thread::sleep_for(std::chrono::seconds(5));
//				std::cout << "\n" << sum << " Number recived in thread 2" << std::endl;
//				std::cout << "\n" << square(sum) << " Square of recived Number in thread 2" << std::endl;
//			}
//		});
//	std::this_thread::sleep_for(std::chrono::seconds(5));
//	ak(RECIVED_SIGNAL);
//} 
//int square(int sum)
//{
//	return sum * sum;
//} 
//int main()
//{
//	std::thread t1(thread1);
//	std::thread t2(thread2);    
//	t1.join();
//	t2.join();
//}
//
//
//
//
//
//
//
//
////#include<iostream>
////#include<thread>
////#include<mutex>
////#include<boost/signals2.hpp>
////
//////#define RECIVED_SIGNAL
//////#define NOT_RECIVED_SIGNAL
////
////boost::signals2::signal<void(int)> sig1;
////boost::signals2::signal<void(int)> sig2;
////
////std::mutex mtx;
////
////int square(int sum);
////
////void thread1()
////{
////	int sum = 0;
////	std::cout << "\nInside Thread 1\n";
////	for (int i = 0; i <= 10; i++)
////	{
////		sum += i;
////		//std::cout << i << "\t";
////	}
////	std::cout << std::endl;
////	std::cout << "\n" << sum << " sum value in thread 1 " << std::endl;
////	std::this_thread::sleep_for(std::chrono::seconds(3));
////	sig1(sum);
////	/*sig2.connect([](int recivedSignalNumber) {
////		std::cout << "Recived Signal Number " << recivedSignalNumber << std::endl;
////	*///if (recivedSignalNumber == RECIVED_SIGNAL)
////	//{
////	//	std::cout << "\nSignal is recived in Thread 2 function " << std::endl;
////	//}
////	//else {
////	//	//Not recived send again
////	//	std::cout << "\nsending Data again " << std::endl;
////	//}
////	//	});
////}
////
////int square(int sum)
////{
////	return sum * sum;
////}
////
////int main()
////{
////	std::thread th1(thread1);
////
////	th1.join();
////
////
////	return 0;
////}