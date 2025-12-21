#include<iostream>
using namespace std;
int main()
{
    int row;
    cout<<"Enter the number of row in 2D array : ";
    cin>>row;
    int colum;
    cout<<"Enter the number of colum in 2D array : ";
    cin>>colum;
    int **arr = new int*[row];
    cout<<"Address of pointer in satic memory &arr = "<<&arr<<endl;
    cout<<"Address of all row in heap memory : "<<endl;
    cout<<"row_add.   value_of_row "<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<arr+i<<"  ";
        cout<<arr[i]<<endl;
    }
    
    for (int i = 0; i < row; i++)
    {
        arr[i]=new int[colum];
    }
    cout<<"\nAfter allocation(colum) Address of all row in heap memory : "<<endl;
    cout<<"row_add.   value_of_row"<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<arr+i<<"  ";
        cout<<arr[i]<<endl;
    }
    cout<<"Address of all element : "<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout<<&arr[i][j]<<" ";
        }
        cout<<endl;
        
    }
    for (int i = 0; i < row; i++)
    {
        delete []arr[i];
    }
    delete []arr;
    
    
}