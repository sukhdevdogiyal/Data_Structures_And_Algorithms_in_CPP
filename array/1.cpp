//#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

    //Write your countBits function here
    int countBits(int n)
    {
        int count=0;
        while(n!=0)
        {
            if(n%2==1)
            {
                cout<<"y"<<n;
                count++;
            }
            n=n>>1;
        }
        return count;
    }

int main() {
    string s='x';
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}