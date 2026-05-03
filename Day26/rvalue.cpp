#include<iostream>
#include<utility>
using namespace std;

void check(int &l)
{
    cout << "L Value: " << "\n";
}

void check(int &&r)
{
    cout << "rvalue" << r <<"\n";
}

/*
Short note:
- lvalue: has a name/address and can appear on the left side of assignment.
  Example: a, *a
- rvalue: temporary value, usually has no stable name.
  Example: 10
- move(x): does not move by itself; it casts x to an rvalue so rvalue overloads can run.
*/

int main()
{
    int *a = new int(10);
    check(*a);
    check(10);
    check(move(*a));
    cout << *a;
    delete a;
    return 0;
}
