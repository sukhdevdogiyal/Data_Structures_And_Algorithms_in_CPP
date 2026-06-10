// 51. N-Queens
// https://leetcode.com/problems/n-queens/description/
// Backtracking/Recursion/Simulation
// T.C = O(N!)
// S.C = O(N^2)
#include <iostream>
#include <vector>
using namespace std;
bool attack(int n, int i, int j, vector<string> &solution)
{
    // check same coloum
    for (int row = i - 1; row >= 0; row--)
    {
        if (solution[row][j] == 'Q')
            return false;
    }
    // check left digonal
    for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--)
    {
        if (solution[row][col] == 'Q')
            return false;
    }
    // check right digonal
    for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++)
    {
        if (solution[row][col] == 'Q')
            return false;
    }
    return true;
}
void solve(int n, int i, vector<vector<string>> &allsolution, vector<string> &solution)
{
    if (i == n)
    {
        allsolution.push_back(solution);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (attack(n, i, j, solution))
        {
            // put Queen
            string row(n,'.');
            row[j] = 'Q';
            // put queen jth coloum
            solution.push_back(row);
            // recurtion for next row
            solve(n, i + 1, allsolution, solution);
            // delete Queen jth coloum for Queen put next coloum
            solution.pop_back();
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> allsolution;
    vector<string> solution;

    solve(n, 0, allsolution, solution);
    return allsolution;
}
void print(int n, vector<string> &solution)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the no. of Queen : ";
    cin >> n;
    cout << endl
         << endl;
    vector<vector<string>> solution = solveNQueens(n);
    cout << "-: Print all solution of N-Queen :-" << endl;
    for (int i = 0; i < solution.size(); i++)
    {
        cout << "Solution no. : " << i + 1 << endl;
        print(n, solution[i]);
        cout << endl;
    }

    return 0;
}
