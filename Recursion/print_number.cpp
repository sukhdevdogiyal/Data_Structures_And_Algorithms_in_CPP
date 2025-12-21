#include<iostream>
using namespace std;
void print(int n) // Head recursion
{
    // Base case 
    if (n<=0)
    {
        return;
    }
    // recursive relation
    print(n-1);
    // processing part
    cout<<n<<endl;
    return;
    
}
void reverseprint(int n) // Tail recursion
{
    // base case
    if (n<=0)
    {
        return;
    }
    // processing part
    cout<<n<<endl;
    // recursive relation
    reverseprint(n-1);
    return ;
    
}
int main(int argc, char const *argv[])
{
    int n=10;
    cout<<"Print number 1 to "<<n<<endl;
    print(n);
    cout<<"Print number reverse oder "<<n<<" to 1"<<endl;
    reverseprint(n);
    return 0;
}
