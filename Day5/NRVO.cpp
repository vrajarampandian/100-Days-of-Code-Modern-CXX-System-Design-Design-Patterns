#include<iostream>
using namespace std;

class Test
{
    public:
    Test()
    {
        cout << "Constructor" << "\n" ;
    }
    Test(const Test & t)
    {
        cout << "Copy Constructor" << "\n";
    }
    Test(Test &&t)
    {
        cout << "Move Constructor" << "\n";
    }
};

// NRVO candidate:
// 't' is a named local object.
// The compiler may optimize this and construct 't' directly
// into the object in main(). If it does not apply NRVO,
// the move constructor is usually called instead.
Test create()
{
    Test t;
    return t;
}

// Guaranteed copy elision in C++17 and later:
// This returns an unnamed temporary, so no copy/move is needed.
Test createGuaranteed()
{
    return Test{};
}

int main()
{
    cout << "NRVO example:\n";
    Test t = create();

    cout << "\nGuaranteed copy elision example:\n";
    Test t2 = createGuaranteed();

    cout << "\nExplanation:\n";
    cout << "1. 'return t;' uses NRVO if the compiler chooses.\n";
    cout << "2. NRVO is optional, so Move Constructor may still appear.\n";
    cout << "3. 'return Test{};' is guaranteed copy elision in C++17+.\n";
    cout << "4. Debug builds often show fewer optimizations.\n";

    return 0;
}
