#include<iostream>
#include<memory>
using namespace std;

class B;

class A
{
    public:
    shared_ptr<B> b;
    ~A()
    {
        cout << "A destroyed" << "\n";
    }
};

class B
{
    public:
    //shared_ptr<A> a; // 
    weak_ptr<A> a;
    ~B()
    {
        cout << "B destroyed " << "\n";
    }
};


int main()
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->b = b; // A owns B;
    b->a = a; // line no 20 if declared share_ptr then cycle created never call destructor
    cout<< "End" << "\n";
    return 0;
}