#include<iostream>
using namespace std;
int prime(int n){
    for (int i = 2; i <n; i++)
    {
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
main()
{
    int n;
    cout<<"Enter the number \n";
    cin>>n;
    cout<<"1 to n Prime no ";
    for (int i = 1; i <=n; i++)
    {
        int ans=prime(i);
        if(ans==1)
        {
            cout<<" "<<i;
        }
    }
    
    
}