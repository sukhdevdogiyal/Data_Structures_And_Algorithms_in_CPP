// 17. Letter Combinations of a Phone Number
#include <iostream>
#include <vector>

using namespace std;
void combination(string &digits, vector<string> &map, string &output, vector<string> &ans, int index)
{
    // cout<<"yes"<<index<<" ";
    //  base case
    if (index >= digits.size())
    {
        // cout<<output<<endl;
        ans.push_back(output);
        return;
    }
    // cout<<"yes"<<index<<endl;
    string str = map[digits[index] - '0'];
    // cout<<" "<<str;
    for (int i = 0; i < str.size(); i++)
    {
        output.push_back(str[i]);
        // cout<<" "<<output<<" ";
        combination(digits, map, output, ans, index + 1);
        // cout<<" "<<output<<" ";
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    vector<string> ans;
    combination(digits, map, output, ans, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    string digits = "23";
    cout << "Leetcode Q = 17 :- Letter Combinations of a Phone Number " << endl;
    cout << "Input : " << digits << endl;

    vector<string> ans = letterCombinations(digits);

    cout << "Output : { ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "\"" << ans[i] << "\" , ";
    }
    cout << "}";

    return 0;
}
