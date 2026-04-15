#include<iostream>
using namespace std;

// N is known at compile time.
template<int N>
// constexpr lets the result be computed during compilation.
constexpr int factorial()
{   
    // Only the valid branch is compiled.
    if constexpr (N <= 1) {
        return 1;
    } else {
        return N * factorial<N - 1>();
    }
}

int main()
{
    // Computed at compile time.
    constexpr int val = factorial<5>();
    cout << val << "\n";
    return 0;
}
