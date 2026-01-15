// Bottom view of Binary tree
// GFG
#include <iostream>
#include <map>
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

// Bottom View of Binary Tree
vector<int> bottomview(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> bottomNode;   // horizontal number map with data only bottom node
    queue<pair<Node *, int>> q; // queue store pair - node link with horizontal number
    q.push(make_pair(root, 0)); // push root node
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int num = temp.second;

        // corresponding horizontal distance maping present then update
        // else create new maping
        bottomNode[num] = frontNode->data;

        // left child push
        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, num - 1));
        // right child push
        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, num + 1));
    }
    // bottomNode data push into ans
    for (auto i : bottomNode)
    {
        ans.push_back(i.second);
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
    cout << "Bottom View of Binary Tree 1 : ";
    vector<int> ans = bottomview(root);
    print(ans);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, 3, 4, -1, -1, -1, -1, 5, 6, -1, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Bottom View of Binary Tree 2 : ";
    ans = bottomview(root1);
    print(ans);

    cout << endl;

    // tree 2
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 6, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    cout << "Bottom View of Binary Tree 3 : ";
    ans = bottomview(root2);
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
   /     /
  3     6
 /
4

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
