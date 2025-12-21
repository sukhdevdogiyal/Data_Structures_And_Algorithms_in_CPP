#include<iostream>
using namespace std;
main()
{
    cout<<"ASCII value of \n";
    for (int i = 0; i <=15; i++)
    {
        char ch=i;
        cout<<i<<" : "<<ch<<"\t";
    }
   cout<<endl;
    for (int i = 16; i <=254; i++)
    {
        char ch=i;
        cout<<i<<" : "<<ch<<"\t\t";
        
    }
    
}