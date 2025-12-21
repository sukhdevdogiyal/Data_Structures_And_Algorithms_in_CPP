// 240. Search a 2D Matrix II
#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        int s = 0, e = col - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (matrix[i][mid] == target)
            {

                return true;
            }
            else if (matrix[i][mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return false;
}
bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int rowind = 0;
    int colind = col - 1;
    while (rowind < row && colind >= 0)
    {
        int element = matrix[rowind][colind];
        if (element == target)
        {
            return 1;
        }
        else if (element < target)
        {
            rowind++;
        }
        else
            colind--;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    // int arr[3][4];
    // vector<vector<int>>arr={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    // int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout<< "5 search in 2D matrix = " << searchMatrix(arr, 5)<<endl;
    cout<< "20 search in 2D matrix = " << searchMatrix(arr, 20)<<endl;
    
}
