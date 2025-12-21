#include <iostream>
#include <cstring>
using namespace std;

// create Hero class
class Hero
{
    // prperties
public:
    double d;
    int Heath;
    char level;
    char *name;
    Hero()
    {
        name = new char[100];
        // name=(char*)"sukhdev";
        strcpy(name, "sukhdev");
    }

    // behaviors
    void attack();
    void defence();
    void dance();
};

class deep
{
public:
    int *a;
    deep(int val)
    {
        a = new int(val);
    }
    deep(deep &other)
    {
        a = new int(*other.a);
    }
};

int main()
{
    cout << "Shallow copy" << endl;
    Hero h1; // default constructor hamesa shallow copy karta hai
    Hero h2(h1);
    cout << "Befor change" << endl;
    cout << "h1.name : " << h1.name << endl;
    cout << "h2.name : " << h2.name << endl;
    cout << "h2.name[0] = 'd'" << endl;
    h2.name[0] = 'd';
    cout << "After change" << endl;
    cout << "h1.name : " << h1.name << endl;
    cout << "h2.name : " << h2.name << endl;

    cout << "\nDeep copy" << endl;
    deep d1(5);
    deep d2 = d1;
    cout << "Befor change" << endl;
    cout << "d1.a : " << *d1.a << endl;
    cout << "d2.a : " << *d2.a << endl;

    cout << "*d2.a = 339" << endl;
    *d2.a = 339;
    cout << "After change" << endl;
    cout << "d1.a : " << *d1.a << endl;
    cout << "d2.a : " << *d2.a << endl;

    cout << "\n copy assignment operator";
    deep d3(8);
    deep d4(10);
    cout << "Befor change" << endl;
    cout << "d3.a : " << *d3.a << endl;
    cout << "d4.a : " << *d4.a << endl;

    cout << "d4 = d3" << endl;
    d4 = d3;
    cout << "After change" << endl;
    cout << "d3.a : " << *d3.a << endl;
    cout << "d4.a : " << *d4.a << endl;

    return 0;
}
