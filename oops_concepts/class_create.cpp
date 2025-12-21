#include <iostream>
//  #pragma pack(1)
/*
Most of the compilers provide nonstandard extensions
 to switch off the default padding like pragmas or command line switches.
 Consult the documentation of the respective compiler for more details.
 */

using namespace std;

// create Hero class
class Hero
{
    // prperties
    //  all variable decleare in hight to low size because minimize padding
    double d;      // 8 size
    int Heath;     // 4 size
    char level;    // 1 size
    char name[50]; // 50 size
    /* highest size double 8 other total size 55
    55 not muntiple of 8 next muntiple of 8 is 56
    than tatal size = 8 +56 = 64 */
    // behaviors
    void attack();
    void defence();
    void dance();
};

class test
{
};
int main()
{
    // create Hero class object
    // Hero ob;
    cout << "Size of non empty class = " << sizeof(Hero) << endl;

    test t1;
    cout << "size of empty class = " << sizeof(t1) << endl;
    return 0;
}
