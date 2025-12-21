#include<iostream>
using namespace std;
main()
{
    int a,b,c;
    cout <<"Enter the side of triangl :"<<endl;
    cin>>a>>b>>c;
    cout<<"\na="<<a<<"\nb="<<b<<"\nc="<<c;
    if ((a<(b+c))&&(b<(a+c))&&(c<(b+a)))
    {
        cout<<"\ntriangl is valid";
    }
    else
    {
        cout<<"\nGiven side tringle is not valid ";
    }
    
}