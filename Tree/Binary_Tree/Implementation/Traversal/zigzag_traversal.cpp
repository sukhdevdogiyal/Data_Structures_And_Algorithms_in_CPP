// zig zag tree traversal
// GFG
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildtree(int *data, int &i)
{
    i++;
    if (data[i] == -1)
        return NULL;

    Node *root = new Node(data[i]);
    root->left = buildtree(data, i);
    root->right = buildtree(data, i);
    return root;
}

vector<int> zigzag(Node *root)
{
    queue<Node *> q;
    if (root != NULL)
        q.push(root);
    vector<int> ans;
    bool lefttoright = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> result(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            int index = lefttoright ? i : size - i - 1;
            result[index] = temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        lefttoright = !lefttoright;
        for (auto i : result)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    cout << "Tree 1 ZigZag Traversal : ";
    vector<int> ans = zigzag(root);
    print(ans);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, 3, 4, -1, -1, -1, -1, 5, 6, -1, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Tree 2 ZigZag Traversal : ";
    ans = zigzag(root1);
    print(ans);

    cout << endl;

    return 0;
}
/*
Tree 1 :-

     1
   /   \
  3     5
 / \    /
7  11   17

InOrder Traversal : 7 3 11 1 17 5

Tree 2 :-

       1
     /   \
    2     5
   /     /
  3     6
 /
4

*/
