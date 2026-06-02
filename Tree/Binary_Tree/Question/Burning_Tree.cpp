// Burning Tree
// GFG
#include <iostream>
#include <queue>
#include <unordered_map>
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
int minTime(Node *root, int target)
{
    // create map node to parent and find target node
    unordered_map<Node *, Node *> nodeToParent;
    // using level ordered traversal
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    Node *targetNode = NULL;
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp->data == target)
            targetNode = temp;
        q.pop();
        if (temp->left)
        {
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }

    // Burning
    unordered_map<Node *, bool> visited;
    q.push(targetNode);
    visited[targetNode] = true;
    int time = 0;
    while (!q.empty())
    {
        bool flag = false;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            // left child
            if (temp->left && !visited[temp->left])
            {
                flag = true;
                visited[temp->left] = true;
                q.push(temp->left);
            }
            // right child
            if (temp->right && !visited[temp->right])
            {
                flag = true;
                visited[temp->right] = true;
                q.push(temp->right);
            }
            // parent
            if (nodeToParent[temp] && !visited[nodeToParent[temp]])
            {
                flag = true;
                visited[nodeToParent[temp]] = true;
                q.push(nodeToParent[temp]);
            }
        }
        if (flag)
            time++;
    }
    return time;
}
int main(int argc, char const *argv[])
{

    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    int target = 7;
    cout << "Target : " << target << endl;
    cout << "Minimum time required to burn the entire tree : " << minTime(root, target) << endl;
    cout << endl;

    // tree 2
    int data1[] = {8, 4, 3, 3, -1, -1, -2, -1, -1, 2, -1, 1, -1, -1, 5, -1, 2, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    target = 5;
    cout << "Target : " << target << endl;
    cout << "Minimum time required to burn the entire tree : " << minTime(root1, target) << endl;
    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k1 = -1;
    root2 = buildtree(data2, k1);
    target = 9;
    cout << "Target : " << target << endl;
    cout << "Minimum time required to burn the entire tree : " << minTime(root2, target) << endl;
    cout << endl;
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

       8
     /   \
    4     5
   / \     \
  3   2     2
 / \   \
3  -2   1

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
