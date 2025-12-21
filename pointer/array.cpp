#include <iostream>
using namespace std;
void fun(int arr[]);
int main(int argc, char const *argv[])
{
    int arr[5] = {90, 2, 3, 4, 5};
    cout << "arr = " << arr << endl;
    cout << "&arr = " << &arr << endl;
    cout << "&arr[0] = " << &arr[0] << endl;
    cout << "*arr = " << *arr << endl;
    cout << "*arr+3 = " << *arr + 3 << endl;
    cout << "*(arr+3) = " << *(arr + 3) << endl;
    cout << "1[arr] = " << 1 [arr] << endl;

    int *p = &arr[0];
    cout << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    cout << "sizeof(p) = " << sizeof(p) << endl;
    cout << "sizeof(&p) = " << sizeof(&p) << endl;
    cout << "sizeof(*arr) = " << sizeof(*arr) << endl;
    cout << "sizeof(&arr) = " << sizeof(&arr) << endl;

    // symbol table value not change
    // or arr is first index address
    // arr= arr+1;

    // this is possible
    int *p1 = &arr[0];
    cout << "befor p1 = " << p1 << endl;
    p1 = p1 + 1;
    cout << "after p1 = " << p1 << endl;

    // array in function
    cout << endl
         << "array in function" << endl;
    int *p2 = &arr[0];
    fun(arr); // pass array as a pointer

    fun(arr + 2); // a part of array pass possible
    return 0;
}

void fun(int arr[10])
{
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    cout<<"arr[0] = "<<arr[0]<<endl;
}
