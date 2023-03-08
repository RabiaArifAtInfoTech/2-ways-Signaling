//.......Solution of Race Condition..........
#include<iostream>
#include<boost/thread.hpp>
#include<boost/chrono.hpp>
#include<vector>


using namespace std;

std::vector<int> vec;

boost::mutex mu;
boost::condition_variable cond;
void function1()
{
	int count = 1;
	int i = 0;
	while (count <= 10)
	{
		boost::unique_lock<boost::mutex> locker(mu);
		vec.push_back(count);
		cout << "\nt1: vec[" << i << "] : " << count << endl;
		i++;
		locker.unlock();

		cond.notify_one(); //notify one waiting thread if there is one.
		boost::this_thread::sleep_for(boost::chrono::seconds(1));
		count++;
	}
}

void function2()
{
	int data = 0;
	while (data != 10)
	{
		boost::unique_lock<boost::mutex>locker(mu);
		//cond.wait(locker); //Error: Spurious wakeup call (sometimes)
		cond.wait(locker, []() { return !vec.empty(); });
		data = vec.back();
		vec.pop_back();
		//locker.unlock();
		cout << "\nt2 got a value from t1 : " << data << endl;
	}
}
int main()
{
	boost::thread t1(function1);
	boost::thread t2(function2);
	t1.join();
	t2.join();
	return 0;

}
