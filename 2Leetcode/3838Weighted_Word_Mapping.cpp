// 3838. Weighted Word Mapping
// https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13
#include <iostream>
#include <vector>
using namespace std;
string mapWordWeights(vector<string> &words, vector<int> &weights)
{
    string ans;
    for (auto w : words)
    {
        int sum = 0;
        for (auto l : w)
        {
            sum += weights[l - 'a'];
        }
        int ch = 25 - sum % 26;
        ans.push_back('a' + ch);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<string> words;
    vector<int> weights;
    words = {"abcd", "def", "xyz"};
    weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
    cout << "Weighted word mapping : " << mapWordWeights(words, weights) << endl;
    cout << endl;

    words = {"a", "b", "c"};
    weights = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Weighted word mapping : " << mapWordWeights(words, weights) << endl;
    cout << endl;

    words = {"abcd"};
    weights = {7, 5, 3, 4, 3, 5, 4, 9, 4, 2, 2, 7, 10, 2, 5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5};
    cout << "Weighted word mapping : " << mapWordWeights(words, weights) << endl;
    cout << endl;
    return 0;
}
