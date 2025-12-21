#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> v, int s, int e)
{
    int n=e;
    int mid = -1, ans = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        //cout<<"mi"<<mid;
        if (v[mid] > v[n])
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}
int binary(vector<int> v, int s, int e,int t)
{
    int mid = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        //cout<<mid;
        if (v[mid] ==t)
        {
            //ans=mid;
            //break;
            return mid;
        }
        else if(v[mid]>t)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {3,1};
    //vector<int> v = {1};
    //vector<int> v = {4, 5, 6, 7, 8, 0, 1, 2};
    int second = search(v, 0, v.size() - 1);
    //cout<<second;
    int target=1;
    if (target >= v[0]&&second>0)
    {
        cout<<binary(v,0,second-1,target);
    }
    else
    {
        cout<<binary(v,second,v.size()-1,target);
    }
    return 0;
}