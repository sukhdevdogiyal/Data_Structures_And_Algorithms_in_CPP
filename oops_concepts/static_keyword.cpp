#include <iostream>
using namespace std;
class Hero
{
public:
    static int timetocomplete;
    int a;
    static void fun()
    {
        int b=99;
        cout<<"call static function"<<endl;
        cout<<"static variable = "<<timetocomplete<<endl;
        cout<<"b = "<<b;
        //a=93; // a is a non static 
    }
};
int Hero ::timetocomplete = 5;
int main(int argc, char const *argv[])
{
    cout << Hero::timetocomplete << endl;
    Hero::fun();
    return 0;
}
