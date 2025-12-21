#include<iostream>
using namespace std;
void reverse(char *str,int s,int e)
{
    if (s>e)
    {
        return;
    }
    swap(str[s++],str[e--]);
    reverse(str,s,e);
    
    return ;
    
}
int main(int argc, char const *argv[])
{
    char str[]="sukhdev";
    cout<<str<<endl;
    int n = sizeof(str);
    reverse(str,0,n-2);
    cout<<str;
    
    return 0;
}
