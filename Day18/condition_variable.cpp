#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cv;
bool ready = false;

void worker()
{
    //unique_lock - can lock/unlock manually
    //can defer locking
    //required for condition_variable
    unique_lock<mutex> ul(m);
    // wait until ready = true
    cv.wait(ul, []{return ready;});
    cout << "Worker thread running" << "\n";
}

int main()
{
    thread t1(worker);
    this_thread::sleep_for(chrono::seconds(3));
    {
        lock_guard<mutex> lock(m);
        ready = true;
    }
    cout << "Nofity:" << "\n"; 
    cv.notify_one();
    t1.join();
    return 0;
}