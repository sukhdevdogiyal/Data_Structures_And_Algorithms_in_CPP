#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a=3;
    int b=9;
    int c=4;
    cout<<"Address of a = "<<&a<<endl;
    cout<<"Address of b = "<<&b<<endl;
    cout<<"Address of c = "<<&c<<endl;
    int *arr[3];
    arr[0]=&a;
    arr[1]=&b;
    arr[2]=&c;
    cout<<"\nPrint value is store in array :"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
    }
    cout<<"\nPrint value of store in given address :"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<"*arr["<<i<<"] = "<<*arr[i]<<endl;
    }
    


    return 0;
}
