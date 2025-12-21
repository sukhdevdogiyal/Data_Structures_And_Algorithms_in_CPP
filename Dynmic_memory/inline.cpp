#include <iostream>
using namespace std;
inline int add(int a, int b)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "hi" << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "hi" << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "hi" << endl;
    }

    return a + b;
}
int main()
{
    int a = 4, b = 3;
    int sum = add(a, b);
    cout << "Sum = " << sum;
}

// run bellow commend create .s file then check .s file add function ki call hua ya nahi
// g++ -O2 -S test.cpp -o test.s
