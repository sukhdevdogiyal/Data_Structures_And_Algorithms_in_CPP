// T.C. = O(9^(N^2))
// S.C = O(N^2)
// Backtracking/Recursion
#include <iostream>
#include <vector>
using namespace std;
bool issafe(int row,int col,vector<vector<char>> &board,char val)
{
    for (int i = 0; i < 9; i++)
    {
        // row check
        if (board[row][i]==val)
        {
            return false;
        }
        // coloum check
        if (board[i][col]==val)
        {
            return false;
        }
        // 3*3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board)
{
    int n= board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                for (char val = '1'; val <='9'; val++)
                {
                    if(issafe(i,j,board,val))
                    {
                        board[i][j] = val;
                        bool solutionpossible = solveSudoku(board);
                        if(solutionpossible)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            } 
        } 
    }
    return true;
}
void print(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    print(board);
    return 0;
}
