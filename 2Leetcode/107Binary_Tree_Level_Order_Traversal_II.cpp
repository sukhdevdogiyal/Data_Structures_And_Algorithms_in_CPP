// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
// Reverse Level Order Traversal

#include <iostream>
#include <queue>
#include <stack>
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

Node *buildtree(Node *root, int *data)
{
    static int i = -1;
    i = i + 1;
    root = new Node(data[i]);
    if (data[i] == -1)
        return NULL;
    root->left = buildtree(root->left, data);
    root->right = buildtree(root->right, data);
    return root;
}
vector<vector<int>> levelOrderBottom(Node *root)
{
    vector<vector<int>> ans;
    vector<int> level;
    if (root == NULL)
        return ans;
    // store a level
    queue<Node *> q;
    q.push(root);
    // push null for level complente
    q.push(NULL);
    // use stack for store level order traversal
    stack<Node *> s;
    s.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp);
        if (temp)
        {
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
        else
        {
            if (!q.empty())
                q.push(NULL);
        }
    }
    if (!s.top())
        s.pop();
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        if (temp)
        {
            level.push_back(temp->data);
        }
        else
        {
            ans.push_back(level);
            level.clear();
        }
    }
    return ans;
}
void print(vector<vector<int>> arr)
{
    cout << "Reverse Level Order Traversal : " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    root = buildtree(root, data);
    vector<vector<int>> ans = levelOrderBottom(root);
    print(ans);

    return 0;
}
/*
Tree :-

     1
   /   \
  3     5
 / \    /
7  11   17

*/
