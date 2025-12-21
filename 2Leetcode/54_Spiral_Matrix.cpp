#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // int arr[3][4];
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //int arr[3][4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};
    int n =3,m=4;
    int sr = 0;
    int sc = 0;
    int er = n-1;
    int ec = m-1;
    while (1)
    {
        for (int c = sc; c <=ec; c++)
        {
            cout<<arr[sr][c]<<" ";
        }
        sr++;
        if(sr>er)break;
        for (int r = sr; r <=er; r++)
        {
            cout<<arr[r][ec]<<" ";
        }
        ec--;
        if(sc>ec)break;
        for (int c = ec; c >=sc; c--)
        {
            cout<<arr[er][c]<<" ";
        }
        er--;
        if(sr>er)break;
        for (int r = er; r >=sr; r--)
        {
            cout<<arr[r][sc]<<" ";
        }
        sc++;
        if(sc>ec)break;
    }
    


}