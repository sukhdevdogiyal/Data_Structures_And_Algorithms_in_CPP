// 48. Rotate Image

// wrong ans

#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    int c1 = row - 1;
    int c2 = c1;
    while (c1--)
    {
        int sr = 0, sc = 0;
        int er = row - 1, ec = col - 1;
        // cout << "yes";
        while (sr < er && sc < ec)
        {
            int temp = matrix[sr + 1][sc];
            for (int i = sc; i <= ec; i++)
                swap(temp, matrix[sr][i]);
            // sr++;
            // if (sr>er) break;

            for (int i = sr + 1; i <= er; i++)
                swap(temp, matrix[i][ec]);
            // ec--;
            // if (sc>ec) break;

            for (int i = ec - 1; i >= sc; i--)
                swap(temp, matrix[er][i]);
            // er--;
            // if (sr>er) break;

            for (int i = er - 1; i > sr; i--)
                swap(temp, matrix[i][sc]);
            // sc++;
            // if (sc>ec) break;

            sr++;
            ec--;
            er--;
            sc++;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1, 2},
                                  {4, 5}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    matrix = {{1, 2, 3},
              {4, 5, 6},
              {7, 8, 9}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    matrix = {{5, 1, 9, 11},
              {2, 4, 8, 10},
              {13, 3, 6, 7},
              {15, 14, 12, 16}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)

    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
