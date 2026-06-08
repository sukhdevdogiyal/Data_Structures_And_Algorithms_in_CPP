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
bool searchBST(Node *root,int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {10, 8, 21, 7, 27, 5, 4, 3};
    Node *root = creatBST(arr);
    int val = 5;
    cout<<val<<"is Present in tree : "<<searchBST(root,val)<<endl;
    val = 9;
    cout<<val<<"is Present in tree : "<<searchBST(root,val)<<endl;
    cout<<endl;
    
    // Tree 2
    arr = {4, 7, 2, 1, 3};
    Node *root1 = creatBST(arr);
    val = 5;
    cout<<val<<"is Present in tree : "<<searchBST(root1,val)<<endl;
    val = 7;
    cout<<val<<"is Present in tree : "<<searchBST(root1,val)<<endl;
    cout<<endl;

    return 0;
}
