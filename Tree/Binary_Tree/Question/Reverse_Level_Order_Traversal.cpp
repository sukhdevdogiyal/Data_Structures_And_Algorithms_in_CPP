// Reverse Level Order Traversal
// GFG

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
vector<int> reverseLevelOrder(Node *root)
{
    // store level order
    queue<Node *> q;
    q.push(root);

    // store reverse level order
    stack<int> s;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp)
        {
            s.push(temp->data);
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
void print(vector<int> arr)
{
    cout << "Reverse Level Order Traversal : ";
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
    vector<int> ans = reverseLevelOrder(root);
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
