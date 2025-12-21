#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int i = 9;
    int *ptr = &i;
    int num = 300;
    cout<<"sizeof(*ptr) = "<<sizeof(*ptr)<<endl;
    cout << "&i = " << &i << endl;
    cout << "ptr " << ptr << endl;
    cout << *(ptr) << endl;

    ptr = &num;
    cout << *ptr << endl;

    int a = *ptr;
    a++;
    cout << a << endl;
    cout << num << endl;

    int *q = 0; // int *q=ptr;
    q = ptr;
    cout << "q = " << q << endl;
    cout << "*q = " << *(q) << endl;

    float f = 10.5;
    float p = 2.5;
    float *ptr2 = &f;
    (*ptr2)++;
    *ptr2 = p;
    cout << *ptr2 << " " << f << " " << p << endl;

    int o[] = {1, 5, 3, 4};
    int *ppp = (o + 1);
    //*ppp=o;
    cout << *ppp + 9;
    char b[] = "xyz";
    char *c = &b[0];
    cout << c << endl;

/* 
    char *st1 = "abc";
    char *st2 = "def";
    swap(st1, st2);
    cout << st1 << " " << st2;
    char *t = st1;
    st1 = st2;
    st2 = t;
    cout << st1 << " " << st2<<endl;

   char *x = "ninjasquiz";
   char *y = "codingninjas";
   char *t1;
   swap(x, y);
   cout<<x << " "<<y;
   t1 = x;
   x = y;
   y = t1; 
   cout<<" "<<x<< " "<<y;
*/

  //  int aa=9;
  //  void *pp=&aa;
  //  char cc='9';
  //  pp=&cc;
  //  cout<<"\naa = "<<&cc;

   // wild pointer 
   int *pq;
   //*pq=5;
   //cout<<*pq;
    return 0;
}
void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}
