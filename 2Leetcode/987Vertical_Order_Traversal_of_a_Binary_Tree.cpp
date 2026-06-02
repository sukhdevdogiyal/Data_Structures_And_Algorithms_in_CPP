// 987. Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// Vertical tree traversal
// GFG
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
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
// Node number and level maping
void numlevelmaping(Node *root, map<int, vector<Node *>> &numbermap, map<Node *, int> &levelmap, int level, int num)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    numbermap[num].push_back(root);
    levelmap[root] = level;
    numlevelmaping(root->left, numbermap, levelmap, level + 1, num - 1);
    numlevelmaping(root->right, numbermap, levelmap, level + 1, num + 1);
}
vector<vector<int>> verticalTraversal(Node *root)
{
    map<int, vector<Node *>> numbermap;
    map<Node *, int> levelmap;
    numlevelmaping(root, numbermap, levelmap, 0, 0);

    vector<vector<int>> result;
    for (auto i : numbermap)
    {
        map<int, vector<Node *>> levelnodemap;
        for (int j = 0; j < i.second.size(); j++)
        {
            levelnodemap[levelmap[i.second[j]]].push_back(i.second[j]);
        }

        vector<int> samenumber;
        for (auto j : levelnodemap)
        {
            vector<int> samelevel;
            for (int k = 0; k < j.second.size(); k++)
            {
                samelevel.push_back(j.second[k]->data);
            }
            sort(samelevel.begin(), samelevel.end());
            for (int k = 0; k < samelevel.size(); k++)
            {
                samenumber.push_back(samelevel[k]);
            }
        }
        result.push_back(samenumber);
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
        cout << endl;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{

    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 9, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    cout << "Tree 1 Vertical Traversal : " << endl;
    vector<vector<int>> ans = verticalTraversal(root);
    print(ans);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, 3, 4, -1, -1, -1, -1, 5, 6, -1, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Tree 2 vertical Traversal : " << endl;
    ans = verticalTraversal(root1);
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
