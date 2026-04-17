#include<iostream>
using namespace std;

class Test
{
    public:
    int x;
    Test(int a) : x(a)
    {

    }
    // Copy constructor: creates a new object as a copy of another object.
    Test(const Test &obj)
    {
        // Passed by reference to avoid making another copy of the same object.
        // Here it copies only an int, so this is effectively a deep copy.
        // Shallow copy shares the same memory; deep copy makes separate data.
        x = obj.x;
        cout << "copy constuctor" << "\n";
    }

};

int main()
{
    Test t1(10);
    Test t2 = t1; 
    return 0;
}
