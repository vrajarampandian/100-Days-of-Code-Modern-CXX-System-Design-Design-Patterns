#include<iostream>
using namespace std;

class Resource
{
    int *data;
    public:
    Resource(int val)
    {
        // Allocate separate dynamic memory for this object.
        data = new int(val);
    }

    // Deep copy constructor:
    // Creates a brand-new memory location and copies the value.
    //
    // Shallow copy:
    // data = r.data;
    // Both objects point to the same memory, so changing one affects the other.
    // It can also cause double deletion when both destructors run.
    //
    // Deep copy:
    // data = new int(*r.data);
    // Both objects store the same value, but each owns different memory.
    Resource(const Resource &r)
    {
        data = new int(*r.data);
    }

    void setdata(int a)
    {
        *data = a;
    }

    void print()
    {
        cout << "DATA: " << *data << "\n";
    }

    ~Resource()
    {
        // Free only this object's own memory.
        delete data;
    }
};

int main()
{
    Resource R1(10);

    // Calls the deep copy constructor.
    Resource R2 = R1;

    // Change only R1's value.
    R1.setdata(49);

    // R2 still keeps its own copied value.
    R2.print();

    return 0;
}
