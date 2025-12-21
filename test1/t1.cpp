#include <iostream>
#include <vector>
using namespace std;
int maximumFrequency(vector<int> &arr, int n)
{
    int min = arr[0], max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    
    vector<int> count(max - min + 1, 0);
    int index = min - arr[0];
        if (index < 0)
        {
            index = -index;
        }
    int maxfre=index;
    for (int i = 0; i < n; i++)
    {
        int index = min - arr[i];
        if (index < 0)
        {
            index = -index;
        }
        cout<<index<<" ";
        count[index]++;
        // if (count[maxfre] < count[index])
        // {
        //     maxfre=index;
        //     cout<<"ma"<<index;
        // }
        
    }
    for (int i = 0; i < n; i++)
    {
        int index = min - arr[i];
        if (index < 0)
        {
            index = -index;
        }
    
        if (count[index]>count[maxfre])
        {
            maxfre=index;
        }
        
    }
    

    return maxfre+min;
}
int main(int argc, char const *argv[])
{
    //vector<int> arr={1,2,3,1,2};
    //vector<int> arr={4 ,-5, 1};
    vector<int> arr={0, -3, 1, 2, 4, -1, -2, 2, -3, -5};
    //vector<int> arr={1 ,-2, 1, -2};
    //vector<int> arr={2 ,12 ,2 ,11 ,-12, 2 ,-1, 2, 2, 11, 12, 2, -6};
    cout<<maximumFrequency(arr, arr.size());
    return 0;
}
