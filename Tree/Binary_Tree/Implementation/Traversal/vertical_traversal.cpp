// Vertical tree traversal
// GFG
#include <iostream>
#include <map>
#include<unordered_map>
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
// map with number and level each node
void maping(Node *root, int num, int level, map<int, vector<Node *>> &numbermap, map<Node *, int> &levelmap)
{
    if (root == NULL)
        return;
    numbermap[num].push_back(root);
    levelmap[root] = level;
    maping(root->left, num - 1, level + 1, numbermap, levelmap);
    maping(root->right, num + 1, level + 1, numbermap, levelmap);
}
vector<vector<int>> vertical(Node *root)
{
    map<int, vector<Node *>> numbermap; // store number map with node
    map<Node *, int> levelmap;          // each node map with level
    maping(root, 0, 0, numbermap, levelmap);
    vector<vector<int>> result;
    // traversal
    for (auto i : numbermap)
    {
        // level map with node
        map<int, vector<Node *>> ans;
        for (int j = 0; j < i.second.size(); j++)
        {
            // find level
            int l = levelmap[i.second[j]];
            // store same level node
            ans[l].push_back(i.second[j]);
        }

        vector<int> samenum; // same number node data store
        for (auto pair : ans)
        {

            for (int i = 0; i < pair.second.size(); i++)
                samenum.push_back(pair.second[i]->data);
        }
        result.push_back(samenum);
    }
    return result;
}

void print(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
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
    cout << "Tree 1 Vertical Traversal : ";
    vector<vector<int>> ans = vertical(root);
    print(ans);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, 3, 4, -1, -1, -1, -1, 5, 6, -1, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Tree 2 vertical Traversal : ";
    ans = vertical(root1);
    print(ans);

    cout << endl;

    return 0;
}
/*
Tree 1 :-

     1
   /   \
  3     5
 / \    /
7  11   17

InOrder Traversal : 7 3 11 1 17 5

Tree 2 :-

       1
     /   \
    2     5
   /     /
  3     6
 /
4

*/
