#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    int i;
    int j;
    node(int d, int row, int col)
    {
        data = d;
        i = row;
        j = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
// T.C = O(n*klog(k))
// S.C = O(n*k)
vector<int> mergeArrays(vector<vector<int>> &mat)
{
    // use minheap store all array smallest element
    priority_queue<node *, vector<node *>, compare> pq;
    // store all array first element
    for (int i = 0; i < mat.size(); i++)
    {
        node *temp = new node(mat[i][0], i, 0);
        pq.push(temp);
    }

    // merge all array
    // top of pq put into ans and same row new data add into pq
    vector<int> ans;
    while (!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();
        ans.push_back(temp->data);
        int i = temp->i;
        int j = temp->j;
        if (j + 1 < mat[i].size())
        {
            node *next = new node(mat[i][j + 1], i, j + 1);
            pq.push(next);
        }
    }
    return ans;
}
void print(vector<int> arr)
{
    cout << "Merge k sorted array : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{1, 3, 5, 7},
                               {2, 4, 6, 8},
                               {0, 9, 10, 11}};
    vector<int> merge = mergeArrays(mat);
    print(merge);
    cout << endl;

    mat = {{1, 2, 3, 4},
           {2, 2, 3, 4},
           {5, 5, 6, 6},
           {7, 8, 9, 9}};
    merge = mergeArrays(mat);
    print(merge);
    cout << endl;

    return 0;
}
