#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"max(5,23) = "<<max(5,23)<<endl;
    cout<<"min(5,23) = "<<min(5,23)<<endl;

    int a=445;
    int b=235;
    cout<<"befor swap : "<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    swap(a,b);
    cout<<"after swap : "<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;

    string s = "abcde";
    cout<<"befor reverse = "<<s<<endl;
    reverse(s.begin(),s.end());
    cout<<"after reverse = "<<s<<endl;
    reverse(s.begin(),s.end());

    rotate(s.begin(),s.begin()+2,s.end());
    cout<<"after rotate = "<<s<<endl;

    vector<int> v={5,6,44,5,911,4,55};
    cout<<"vector v element :";
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end());
    cout<<"vector v element after sort :";
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"binary_search(v.begin(),v.end(),911) = "<<binary_search(v.begin(),v.end(),911)<<endl;
    cout<<"lower bound of 5 = "<<lower_bound(v.begin(),v.end(),5)-v.begin()<<endl;
    cout<<"upper bound of 5 = "<<upper_bound(v.begin(),v.end(),5)-v.begin()<<endl;
    
    return 0;
}