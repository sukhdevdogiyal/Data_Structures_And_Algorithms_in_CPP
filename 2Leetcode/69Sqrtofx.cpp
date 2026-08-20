// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/description/
#include <iostream>
using namespace std;

int mySqrt(int x) {
    int s=1,e=x;
    long long int mid=s+(e-s)/2;
    long long int ans=0;
    while(s<=e)
     {
        long long int squre=mid*mid;
        if(squre==x)
         {
            return mid;
         }
         if(squre>x)
          {
            e=mid-1;
          }
          else
           {
            ans=mid;
            s=mid+1;
           }
           mid=s+(e-s)/2;
     }
     return ans;
}

int main() {
    int x1 = 16;
    cout << "Test Case 1: " << mySqrt(x1) << endl;

    int x2 = 8;
    cout << "Test Case 2: " << mySqrt(x2) << endl;

    int x3 = 25;
    cout << "Test Case 3: " << mySqrt(x3) << endl;

    return 0;
}
