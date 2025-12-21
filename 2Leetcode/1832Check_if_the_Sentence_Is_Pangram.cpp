// 1832. Check if the Sentence Is Pangram
#include <iostream>
#include<vector>
using namespace std;
bool checkIfPangram(string sentence)
{
    vector<int> count(26, 0);
    for (int i = 0; i < sentence.size(); i++)
    {
        int ind = sentence[i] - 'a';
        count[ind]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == 0)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string st="thequickbrownfoxjumpsoverthelazydog";
    //string st = "leetcode";
    cout<<"string : "<<st<<endl;
    if (checkIfPangram(st))
    {

        cout<<"string is pangram";
    }
    else
    {
        cout<<"string is not pangram";
    }
    
    return 0;
}
