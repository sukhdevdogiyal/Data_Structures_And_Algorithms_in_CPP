#include<iostream>
using namespace std;
class Heap
{
    public:
    int arr[100];
    int size;
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size+1;
        int index = size;
        arr[index] = val;
        while (index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index])
                swap(arr[parent],arr[index]);
            else
                return ;
            index = parent;
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deleteFromHeap()
    {
        if (size==0)
        {
            cout<<"Nothing to Delete"<<endl;
        }
        arr[0] = arr[size];
        size--;
        int index = 1;
        while (arr[index]<max(arr[index*2],arr[index*2+1]))
        {
            int child = -1;
            if (max(arr[index*2],arr[index*2+1])==arr[index*2])
            {
                child = index*2;
            }
            else
                child = index*2+1;
            swap(arr[index],arr[child]);
            index = child;            
        }
    }
};
int main(int argc, char const *argv[])
{
    Heap h;
    h.insert(50);  
    h.insert(55);  
    h.insert(53);  
    h.insert(52);  
    h.insert(54);  
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}
