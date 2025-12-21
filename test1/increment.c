#include<stdio.h>
void solve() {
    int a = 3; 
    //int res = a++ + ++a + a++ + ++a;
    printf("%d", a++ + ++a + a++ + ++a); 
}
void solve2() {
    int a = 3; 
    //int res = a++ + ++a + a++ + ++a;
    printf("%d %d %d %d", a++ , ++a , a++ , ++a); 
}
int main(int argc, char const *argv[])
{
    solve2();
    return 0;
}

