#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void insertNode(Node *root, int val)
{
    Node *temp = root;
    while (1)
    {
        if (temp->data > val)
        {
            if (temp->left == NULL)
            {
                temp->left = new Node(val);
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = new Node(val);
                return;
            }
            temp = temp->right;
        }
    }
}
Node *creatBST(vector<int> arr)
{
    Node *root = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        int element = arr[i];
        if (root == NULL)
        {
            root = new Node(element);
        }
        else
        {
            insertNode(root, element);
        }
    }
    return root;
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {10, 8, 21, 7, 27, 5, 4, 3};
    Node *root = creatBST(arr);
    cout << "Print Preorder : ";
    preorder(root);
    return 0;
}
