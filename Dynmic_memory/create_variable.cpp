#include<iostream>
using namespace std;
int main()
{
    int a =9;// use stack memory called static memory allocation

    //create dynmic variable 
    cout<<"Create Dynmic Memory "<<endl;
    cout<<"1. int type : "<<endl;
    int *p1=new int ;
    *p1=34;
    cout<<"Stack memory address &p1 = "<<&p1<<endl;
    cout<<"Dynmic memory address p1 = "<<p1<<endl;
    cout<<"Value is store inside DM *p1 = "<<*p1<<endl;
    cout<<"sizeof(*p1) = "<<sizeof(*p1)<<endl;
    cout<<"sizeof(p1) = "<<sizeof(p1)<<endl;
    
    cout<<"\n2. char type : "<<endl;
    char *p2=new char ;
    *p2='s';
    cout<<"Stack memory address &p2 = "<<&p2<<endl;
    cout<<"Dynmic memory address p2 = "<<static_cast<void*>(p2)<<endl;
    cout<<"Value is store inside DM *p2 = "<<*p2<<endl;
    cout<<"sizeof(*p2) = "<<sizeof(*p2)<<endl;
    cout<<"sizeof(p2) = "<<sizeof(p2)<<endl;

    // Manually Releasing Dynmic memory
    delete p1;
    delete p2;
}