#include<iostream>
#include<vector>
using namespace std;

class Test
{
    public:
    Test(int a)
    {
        cout << "Constructor " << a <<"\n";
    }
    Test(const Test &obj)
    {
        cout << "Copy constructor " << "\n";
    }
    Test(Test &&obj)
    {
        cout << "Move Constrcutor " << "\n";
    }
};

int main()
{
    vector<Test> t;
    t.reserve(2);

    t.push_back(Test(10));

    // emplace_back passes 20 to Test(int) and constructs the object directly
    // inside the vector. reserve(2) above prevents reallocation here, so no
    // extra move/copy is needed for this insertion.
    t.emplace_back(20);
    return 0;
}
