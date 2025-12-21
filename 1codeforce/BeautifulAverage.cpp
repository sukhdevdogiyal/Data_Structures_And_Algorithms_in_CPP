#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int m;
    vector<vector<int>> input;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            row.push_back(num);
        }
        input.push_back(row);
    }

    for (int i = 0; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j] > max)
            {
                max = input[i][j];
            }
        }
        cout << max << endl;
    }

    return 0;
}
