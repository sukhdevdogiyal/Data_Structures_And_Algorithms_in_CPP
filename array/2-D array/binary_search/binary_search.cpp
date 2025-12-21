#include <iostream>
using namespace std;
 bool searchMatrix(int matrix[3][4], int row ,int col, int target) {
        // int row = r;
        // int col =;
        int s=0;
        int e=row*col-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(matrix[mid/col][mid%col]==target)
            {return 1;}
            else if(matrix[mid/col][mid%col]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return 0;
    }
int main(int argc, char const *argv[])
{
    // int arr[3][4];
    int arr[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    //int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout<<searchMatrix(arr,3,4,13);

}
