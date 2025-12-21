#include<iostream>
using namespace std;
int calculate(int base,int power)
{
    // Base case
    if (power==0)
    {
        return 1;
    }
    return base*calculate(base,power-1);
    
}
int powerm2(int base,int power)
{
    //cout<<power<<endl;
    // Base case
    if (power==0)
    {
        return 1;
    }
    
    
    int ans = powerm2(base,power/2);
    //cout<<(power)<<endl;
    cout<<(ans)<<endl;
    //<<"odd "<<(power&1)<<endl;
    if (!(power&1))//%2==0)
    {
        return ans*ans;
    }
    else
    {
        return base*ans*ans;
        //int ans=powerm2(base,power/2);
    }
    
    
}
int main(int argc, char const *argv[])
{
    int base=3;
    int power=4;
    //cout<<base<<" to the power "<<power<<" is = "<<calculate(base,power)<<endl;
    cout<<base<<" to the power "<<power<<" is = "<<powerm2(base,power);
    return 0;
}
