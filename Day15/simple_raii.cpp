#include<iostream>
#include<mutex>
#include<memory>   // for unique_ptr, make_unique
using namespace std;

// Global mutex shared across functions
std::mutex m;

// RAII Example 1: Mutex handling
void raii2()
{
    // lock_guard acquires the mutex in constructor
    lock_guard<mutex> lock(m);

    // Critical section (protected code)
    // If an exception occurs or function returns early,
    // lock_guard destructor will automatically unlock the mutex

    // No need to call m.unlock() manually -> avoids bugs
}

// RAII Example 2: Dynamic memory management
void raii1()
{
    // unique_ptr manages heap memory
    // Allocates memory and takes ownership
    unique_ptr<int> p = make_unique<int>(10);

    // Even if function exits early,
    // destructor of unique_ptr will automatically delete memory

    if(true)
        return;   // No memory leak
}

int main()
{
    raii1();  // Demonstrates automatic memory cleanup
    raii2();  // Demonstrates automatic mutex unlock

    return 0;
}