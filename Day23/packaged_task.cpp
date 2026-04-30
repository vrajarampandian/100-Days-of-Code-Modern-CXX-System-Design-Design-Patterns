#include<iostream>
#include<future>
using namespace std;

/*
Notes:
- std::packaged_task wraps a callable object, such as a function or lambda.
- It connects that callable to a std::future, which will later hold the result.
- Unlike std::async, packaged_task does not start a new thread by itself.
- The task runs only when we invoke it directly or move it into a thread.
- future.get() waits for the task result and can be called only once.
*/
int add(int a, int b)
{
    // This function will be wrapped inside the packaged_task.
    return a + b;
}

int main()
{
    // Create a task that accepts two ints and produces one int.
    packaged_task<int(int, int)> task(add);

    // Get the future before running the task so we can receive its result later.
    future<int> result = task.get_future();

    // Run the packaged task. This calls add(3, 8) on the current thread.
    task(3, 8);

    // get() waits until the task has finished, then returns the stored value.
    cout << result.get() << "\n";
    return 0;
}
