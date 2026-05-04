#include <iostream>
#include <utility>
using namespace std;

// Called when the argument is an lvalue: a named object with a stable address.
void process(int& x) {
    cout << "lvalue\n";
}

// Called when the argument is an rvalue: a temporary value or explicitly moved value.
void process(int&& x) {
    cout << "rvalue\n";
}

template<typename T>
// T&& is a forwarding reference here because T is deduced by the function call.
void wrapper(T&& arg) {
    // Inside the function, arg has a name, so it is always treated as an lvalue.
    process(arg);

    // Use std::forward<T>(arg) to preserve the original value category.
    // For wrapper(x), it forwards as an lvalue.
    // For wrapper(20), it forwards as an rvalue.
    // process(std::forward<T>(arg));
}

int main() {
    int x = 10;

    wrapper(x);   // x is an lvalue, so T becomes int&
    wrapper(20);  // 20 is an rvalue, so T becomes int
}
