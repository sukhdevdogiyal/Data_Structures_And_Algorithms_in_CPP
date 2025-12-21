#include<iostream>
#include<vector>
using namespace std;
void subset(vector<int>arr,vector<int> output,int index,vector<vector<int>> &ans)
{
    if (index>=arr.size())
    {
        ans.push_back(output);
        return;
    }
    subset(arr,output,index+1,ans);
    int element = arr[index];
    output.push_back(element);
    subset(arr,output,index+1,ans);
}
int main(int argc, char const *argv[])
{
    //vector<int> arr={1,2,3};
    vector<int> arr={1,2,3,5,65};
    cout<<"Leetcode Q = 78 :- SUBSET find "<<endl;
    cout<<"Input set : { ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
    
    vector<int> output;
    vector<vector<int>> ans;
    subset(arr,output,0,ans);
    cout<<"All Subset : "<<endl;
    for (int i = 0; i < ans.size(); i++) {
        cout<<i+1 << ". { ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
