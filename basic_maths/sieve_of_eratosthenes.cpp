#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number ";
    cin>>n;
    int count=0;
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    cout<<"print prime no = ";
    for(int i=2;i<n;i++)
    {
        if (prime[i])
        {
            cout<<i<<" ";
            count++;
            for (int j = i*2; j < n; j=j+i)
            {
                prime[j]=false;
            }
            
        }
    }
    cout<<"\ntotal no. of prime no. in range 1 to "<<n<<" is = "<<count;
    return 0;
}
