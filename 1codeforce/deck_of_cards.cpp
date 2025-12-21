#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int test;
    cin>>test;
    vector<vector<int>> v;
    for (int i = 0; i < test; i++)
    {
        vector<int>v1;
        int n,k,ch;
        cin>>n>>k>>ch;
        v1.push_back(n);
        v1.push_back(k);
        v1.push_back(ch);
        for (int j = 0; j < v1.size(); j++)
        {
            cout<<v1[j];
        }
        
        v.push_back(v1);
    }
    
    // for (int i = 0; i < test; i++)
    // {
    //     int ch0=0,ch1=0,ch2=0;
    //     for (int j = 2; j < v[i].size(); j++)
    //     {
    //         cout<<v[i][j]<<endl;
    //         if (v[i][j]==0)
    //         {
    //             ch0++;
    //         }
    //         if (v[i][j]==1)
    //         {
    //             ch1++;
    //         }
    //         if(v[i][j]==2)
    //         {
    //             ch2++;
    //         }
            
    //     }
    //     cout<<ch0<<" "<<ch1<<" "<<ch2<<endl;
        
    // }
    
    return 0;
}
