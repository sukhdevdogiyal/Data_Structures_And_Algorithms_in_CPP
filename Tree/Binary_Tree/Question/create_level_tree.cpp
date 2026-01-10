#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void buildtree(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter data for root node : ";
    cin >> data;
    if(data==-1)return;
    root = new Node(data);
    q.push(root);
    while (1)
    {
        cout << "Enter data : ";
        cin >> data;
        if (data != -1)
        {
            Node *newnode = new Node(data);
            if (q.front()->left == NULL)
            {
                q.front()->left = newnode;
                q.push(q.front()->left);
            }
            else
            {
                q.front()->right = newnode;
                q.push(q.front()->right);
                q.pop();
            }
        }
        else
        {
            break;
        }
    }
}
void leveloder(Node *&root)
{
    queue<Node *> q; // store child
    if(root==NULL)return;
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
    Node *root=NULL;
    buildtree(root);
    cout << "level order traversal : " << endl;
    leveloder(root);
    return 0;
}
