// Maximum Non-Adjacent Nodes Sum
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
pair<int, int> solve(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;
    // root include
    ans.first = root->data + left.second + right.second;
    // root exclude
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    return ans;
}
int getMaxSum(Node *root)
{
    return max(solve(root).first, solve(root).second);
}
int main(int argc, char const *argv[])
{

    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    cout << "Maximum Non-Adjacent Nodes Sum : " << getMaxSum(root) << endl;
    cout << endl;

    // tree 2
    int data1[] = {1, 2, -1, -1, 5, 6, 8, -1, -1, -1, 7, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Maximum Non-Adjacent Nodes Sum : " << getMaxSum(root1) << endl;
    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    cout << "Maximum Non-Adjacent Nodes Sum : " << getMaxSum(root2) << endl;
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
     2    9
     \  /
     3  7
      \
       4
        \
         5


*/
