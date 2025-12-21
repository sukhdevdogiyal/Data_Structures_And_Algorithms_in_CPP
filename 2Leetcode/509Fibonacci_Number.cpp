// 509. Fibonacci Number

#include <iostream>
using namespace std;
int fib(int n)
{
    // base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // recursion
    int small1 = fib(n - 1);
    int small2 = fib(n - 2);
    // Process
    int big = small1 + small2;
    return big;
}
int main(int argc, char const *argv[])
{
    int n = 10; // 0 1 1 2 3 5 8 13 21 34 55
    cout << "Fibonacci Series " << n << " Element : " << fib(n);
    return 0;
}
