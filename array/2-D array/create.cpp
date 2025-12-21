#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // int arr[3][4];

    int arr[3][4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};

    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,0,11,12};

    // cout<<"enter the element of 2d array : ROW WISE"<<endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin>>arr[i][j];
    //     }
    // }

    // cout<<"enter the element of 2d array : COLOME WISE"<<endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin>>arr[j][i];
    //     }
    // }

    cout << "2D Array : " << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << "2D Array : " << endl;
    for (int col = 0; col < 4; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < 3; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            for (int row = 3 - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
        // cout<<endl;
    }

    return 0;
}
