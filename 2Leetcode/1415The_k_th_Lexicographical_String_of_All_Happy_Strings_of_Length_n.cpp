// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14
/*
 *A happy string is a string that:
   - consists only of letters of the set ['a', 'b', 'c'].
   - s[i] != s[i + 1]
*/

/*
 # Efficiency :-
     -> Current complexity: O(3^N)
     -> Suggested complexity: O(N)
    Suggestions: Use mathematical construction to find the kth string directly instead of generating all possibilities.


*/
#include <iostream>
#include <vector>
using namespace std;
void generateHappyStrings(int n, vector<string> &ans, string output, string &choice)
{
    // base case
    if (output.size() == n)
    {
        ans.push_back(output);
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        // check s[i] != s[i + 1]
        if (output.empty() || !output.empty() && choice[i] != output[output.size() - 1])
        {
            // push
            output.push_back(choice[i]);
            // recursive call
            generateHappyStrings(n, ans, output, choice);
            // back track
            output.pop_back();
        }
    }
}
string getHappyString(int n, int k)
{
    vector<string> ans;
    string output = "";
    string choice = "abc";
    cout << "n = " << n << "\tk = " << k << endl;
    generateHappyStrings(n, ans, output, choice);
    cout << "All Happy String : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "\"" << ans[i] << "\"" << " ";
    }
    cout << "]" << endl;

    if (k > ans.size())
        return "";
    return ans[k - 1];
}
int main(int argc, char const *argv[])
{
    int n = 1, k = 3;
    cout << "Happy String is : " << getHappyString(n, k) << endl;

    cout << endl;
    n = 1, k = 4;
    cout << "Happy String is : " << getHappyString(n, k) << endl;

    cout << endl;
    n = 3, k = 9;
    cout << "Happy String is : " << getHappyString(n, k) << endl;
    return 0;
}
