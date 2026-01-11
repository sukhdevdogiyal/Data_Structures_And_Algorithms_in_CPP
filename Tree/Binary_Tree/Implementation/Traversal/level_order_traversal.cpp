#include <iostream>
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
void leveloder(Node *&root)
{
    queue<Node *> q; // store child
    q.push(root);
    q.push(NULL); // use for level separator
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) // level complete
        {
            cout << endl;
            if (!q.empty()) // for next level complete
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    root = buildtree(root, data);
    cout << "Level Order Traversal : " << endl;
    leveloder(root);

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
