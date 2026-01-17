// Diagonal Traversal of Binary Tree
// GFG
#include <iostream>
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
// diagonal traversal of binary tree
vector<int> diagonal(Node *root)
{
    // use queue store every node left child
    queue<Node *> q;
    // push root
    q.push(root);
    vector<int> ans;
    // process if queue not empty
    while (!q.empty())
    {
        // front element
        Node *temp = q.front();
        q.pop();
        // right part of temp
        while (temp != NULL)
        {
            ans.push_back(temp->data);
            // each node left child push into queue
            if (temp->left)
                q.push(temp->left);
            // update temp
            temp = temp->right;
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
    cout << "Diagonal Traversal of Binary Tree 1 : ";
    vector<int> ans = diagonal(root);
    print(ans);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, -1, -1, 5, 6, 8, -1, -1, -1, 7, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Diagonal Traversal of Binary Tree 2 : ";
    ans = diagonal(root1);
    print(ans);
    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 6, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    cout << "Diagonal Traversal of Binary Tree 3 : ";
    ans = diagonal(root2);
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
