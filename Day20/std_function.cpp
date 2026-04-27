#include<iostream>
#include<functional>
using namespace std;

void hello()
{
    cout << "Hi, Hello" << "\n";
}

int add(int a, int b)
{
    return a +b;
}

class cAdd
{
    public:
    int operator()(int a, int b)
    {
        return a+b;
    }
};

/*
Notes:
- std::function stores any callable object with a matching signature.
- Callable objects can be normal functions, lambdas, or function objects.
- function<int(int, int)> means: takes two int values and returns an int.
*/
int main()
{
    function<void()> f = hello;
    f();

    function<int(int, int)> a = add;
    cout << a(10, 30) << "\n";

    function<int(int, int)> addclass = cAdd();

    cout << addclass(30, 30) << "\n";
    return 0;
}
