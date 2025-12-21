#include<iostream>
using namespace std;

//create Hero class
class Hero
{
    //prperties
    
    double d;  
    int Heath;  
    char level;
    string name;  
public:
    Hero()
    {
        cout<<"simple constructor"<<endl;
    }
    Hero(string nam)
    {
        cout<<"parameter constructor"<<endl;
        this->name=nam;
        cout<<"name = "<<this->name<<endl;
    }
    Hero(Hero &h)
    {
        cout<<"copy constructor"<<endl;
    }

    ~Hero()
    {
        cout<<"call destructor"<<endl;
    }
};


int main()
{
    // create Hero class object
    //Hero ob;
    Hero h1;
 { Hero h2("sukhdev");
   }  Hero h3(h1);

   Hero *h4=new Hero;
   delete h4; // DMA destructor not call automatically
    return 0;
}
