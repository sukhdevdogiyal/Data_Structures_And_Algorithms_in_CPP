#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char arr[20];//input : this is my car
    //cin>>arr; // output this 
    cin.getline(arr,20);// output : this is my car
    cout<<arr;
    

    return 0;
}
