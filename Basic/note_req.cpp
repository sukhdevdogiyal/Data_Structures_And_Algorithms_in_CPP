#include<iostream>
using namespace std;
main()
{
    int n,x=0,y=0,z=0,a=0,b=0,c=0,d=0,e=0;
    cout<<"Enter the amout";
    cin>>n;
    switch (1)
    {
    case 1:
        {
            x=n/500;
            n=n%500;
            cout<<"500 ke note= "<<x<<endl;
        }
    case 2:
        {
             y=n/100;
            n=n%100;
            cout<<"100 ke note= "<<y<<endl;
        }    
    case 3:
        {
            z=n/50;
            n=n%50;
            cout<<"50 ke note= "<<z<<endl;
        }
    case 4:
        {
            a =n/20;
            n=n%20;
            cout<<"20 ke note= "<<a<<endl;
        }
    case 5:
        {
            b=n/10;
            n=n%10;
            cout<<"10 ke note= "<<b<<endl;
        }
    case 6:
        {
             c=n/5;
            n=n%5;
            cout<<"5 ke note= "<<c<<endl;
        } 
    case 7:
        {
            d=n/2;
            n=n%2;
            cout<<"2 ke note= "<<d<<endl;
        }
    case 8:
        {
             e=n/1;
            n=n%1;
            cout<<"1 ke note= "<<e<<endl;
        } 
        break;
                       
    default:
           cout<<"Enter the valid amout";
    }    
    
}