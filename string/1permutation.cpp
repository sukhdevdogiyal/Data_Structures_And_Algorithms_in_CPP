#include<iostream>
#include<vector>
using namespace std;
void nopermutation(string s)
{
    
}
int totalSalary(int basic, char grade) 
{
    float hra = basic*20.0/100.0;

    float da = basic*50/100;
    cout<<da<<endl;
    float allowance;
    float pf = basic*11/100;
    cout<<pf<<endl;
    if(grade=='A') allowance = 1700;
    else if(grade=='B') allowance = 1500;
    else allowance = 1300; 
    cout<<allowance<<endl;
    float total = basic + hra + da + allowance - pf;
    cout<<total<<endl;
    int salary = (int)total;
    double decimal = total-salary;
    if(decimal<0.5)
    {
        return total;
    }
    else
    {
        return total+1.0;
    }
    //return round(total);
}
void interestingPattern(int n)
{
    vector<vector<char>> result;
    for(int i = 1;i<=2;i++)
    {
        vector<char> row;
        for(int j = 1;j<=i;j++)
        {
            
            char ch =(char)n-(char)j+65;
            //cout<<"j";
            cout<<ch;
            row.push_back(ch);
        }
        //cout<<row.at(1);
        result.push_back(row);
    }
    return ;
    // Write your code here
}
int main(int argc, char const *argv[])
{
    //cout<<totalSalary(4567 ,'B');
    interestingPattern(5);

    return 0;
}
