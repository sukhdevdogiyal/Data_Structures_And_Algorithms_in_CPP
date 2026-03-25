// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

#include <iostream>
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
void postorder(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left child
    postorder(root->left, ans);

    // right child
    postorder(root->right, ans);

    // print
    ans.push_back(root->data);
}
void print(vector<int> arr)
{
    cout << "PostOrder Traversal : ";
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
    root = buildtree(root, data);
    cout << endl;
    vector<int> ans;
    postorder(root, ans);
    print(ans);
    cout << endl;

    return 0;
}
/*
Tree :-

     1
   /   \
  3     5
 / \    /
7  11   17

PostOrder Traversal : 7 11 3 17 5 1

*/
