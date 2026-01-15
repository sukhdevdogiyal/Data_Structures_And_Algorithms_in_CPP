// Left view of Binary tree
// GFG
#include <iostream>
#include <map>
#include <queue>
#include <vector>
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

// Approch #1
// Left View of Binary Tree
vector<int> leftview(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root->data);
    bool c = false;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            c = true;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            if (c)
            {
                ans.push_back(temp->data);
                c = false;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
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
    cout << "Left View of Binary Tree 1 : ";
    vector<int> ans = leftview(root);
    print(ans);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, -1, -1, 5, 6, 8, -1, -1, -1, 7, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Left View of Binary Tree 2 : ";
    ans = leftview(root1);
    print(ans);

    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, -1, 5, 6, 8, -1, -1, -1, 7, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    cout << "Left View of Binary Tree 3 : ";
    ans = leftview(root2);
    print(ans);

    cout << endl;

    return 0;
}
/*
Tree 1 :-

     1
   /   \
  3     5
 / \   /
7  11 17

Tree 2 :-

       1
     /   \
    2     5
         / \
        6   7
       /
      8

Tree 3 :-

       1
      /  \
     2    6
     \  /
     3  7
      \
       4
        \
         5


*/
