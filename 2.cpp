/*#define pi 33
#include<iostream>
using namespace std;
main()
 {
 
    int a=pi+1;
    const int b=0;
 cout<<(pi)<<endl<<a<<endl<<b;
 if (!b)
 {
    cout<<"\nyes"<<b;
 }
 char ch;
 cin>>ch;
 ch=toupper(ch);
 cout<<ch;
 
 }*/
/*#include<iostream>
#include<limits.h>
using namespace std;
int updat(int a)
{
   int ans =a*a;
   cout<<a;
   return ans;
}
main()
{
   int a=4,b=5;
   cout<<"a&b = "<<(a&b);
   cout<<"\na|b = "<<(a|b);
   cout<<"\n~a = "<<(~a);
   cout<<"\na^b = "<<(a^b);
   a=updat(a);
   cout<<"\na="<<a<<endl;
   int arr[55],sum=0,maxim=INT_MIN;
   cout<<"arr[6]="<<arr[200]<<endl;
   for (int  i = 0; i < 5; i++)
   {
      cin>>arr[i];
      sum+=arr[i];
      maxim=max(maxim,arr[i]);
   }
   for (int  i = 0; i < 5; i++)
   {
      cout<<arr[i]<<" ";
   }
   int arrsize=sizeof(arr)/sizeof(int);
   cout<<endl<<arrsize;
   cout<<"\nsum= "<<sum;
   cout<<"\nmax= "<<maxim;
}*/

/*
#include<iostream>
#include<algorithm>
using namespace std;
void update(int update[],int n)
{
   update[2]=55;
   for (int i = 0; i <5; i++)
   {
      cout<<update[i]<<" ";
   }
}
main()
 {
   int arr[6]={98,3,4,22,1,88};
   for (int i = 0; i <5; i++)
   {
      cout<<arr[i]<<" ";
   }
   cout<<"\n";
   // update(arr,5);
   for (int i = 0; i <6; i++)
   {
      cout<<arr[i]<<" ";
   }
   cout<<endl;


   for (int i = 0; i < 5; i+=2)
   {
      
   
   
   
      swap(arr[i],arr[i+1]);
   }
   for (int i = 0; i <6; i++)
   {
      cout<<arr[i]<<" ";
   }

   cout<<"\n";
   int s=0,e=6-1;
   while (s<=e)
   {
      swap(arr[s],arr[e]);
      s++;
      e--;
   }
   sort(arr+2,arr+6);
   for (int i = 0; i <6; i++)
   {
      cout<<arr[i]<<" ";
   }



    sort(arr.begin(),arr.end());
        vector<int> v;

        for( int i=0;i<arr.size();i++)
         {
            int count=0;
            
             while(i+1<arr.size()&&arr[i]==arr[i+1])
             {
                count++;
                i++;
             }
             v.push_back(count);
             sort(v.begin(),v.end());
             for(int i=1;i<v.size();i++)
              {
                if(v[i]==v[i-1])
                return false;
              }
              
         }
       return true; 
   
 }*/


#include<iostream>
#include<algorithm>
using namespace std;
main()
{
 int arr[]={-3,0,1,-3,1,1,1,-3,10,0}
  sort(arr.begin(),arr.end());
        vector<int>v;
        for(int i=0;i<arr.size();)
        {
            int count=0;
            int tem=0;
            for(int j=i+1;j<arr.size();j++)
             {
                if(arr[i]==arr[j])
                 {
                    count++;
                    tem=j;
                 }
             }
             v.push_back(count);
             i=tem+1;
        }
       sort(v.begin(),v.end());
       for(int i=0,j=1;i<arr.size()-1,j<arr.size();i++,j++) 
        {
            if(v[i]==v[j])
             {
                return false;
             }
        }
       return true;
    }