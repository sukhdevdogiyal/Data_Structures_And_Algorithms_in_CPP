#include <iostream>
using namespace std;

// create Hero class
class Hero
{
    // prperties

    double d; // By default private
public:
    int Heath;

private:
    char level;

protected:
    char name;

public:
    // behaviors
    void attack();
    void defence();
    void dance();
    void setlevel(char ch)
    {
        level = ch;
    }
    char getlevel()
    {
        return level;
    }
};

int main()
{
    // create Hero class object
    // Hero ob;
    cout << "Size of hero class : " << sizeof(Hero) << endl;
    Hero h1;
    // h1.d = 9.8;    // error: 'double Hero::d' is private within this context
    h1.Heath = 70;
    // h1.name='n';  // error: 'char Hero::name' is protected within this context

    h1.setlevel('A');
    cout << "\nLevel = " << h1.getlevel();
    return 0;
}
