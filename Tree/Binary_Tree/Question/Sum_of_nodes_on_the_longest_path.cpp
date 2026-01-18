// Sum of nodes on the longest path
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
// Approch #1
// function sum and height
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p = make_pair(0, 0);
        return p;
    }
    pair<int, int> lefttree = solve(root->left);
    pair<int, int> righttree = solve(root->right);
    int LH = lefttree.first;
    int RH = righttree.first;
    int height;
    int LS = lefttree.second;
    int RS = righttree.second;
    int sum;
    if (LH == RH)
    {
        height = LH;
        sum = max(LS, RS);
    }
    else if (LH > RH)
    {
        height = LH;
        sum = LS;
    }
    else // LH < RH
    {
        height = RH;
        sum = RS;
    }
    height++;
    sum += root->data;
    pair<int, int> ans;
    ans = make_pair(height, sum);
    return ans;
}
// Sum of nodes on the longest path
// Approch #1
int longestpathsum(Node *root)
{
    return solve(root).second;
}

// Approch #2
// function to find max sum
void solve1(Node*root,int len,int &maxlen,int sum,int &maxsum)
{
    // base case 
    if(root==NULL)
    {
        if(maxlen<len) // if current length greter then update maxsum,length
        {
            maxlen = len;
            maxsum = sum;
        }
        else if(maxlen==len) // if length is equel return max sum
        {
            maxsum = max(sum,maxsum);
        }
        return ;
    }
    sum = sum+root->data;
    solve1(root->left,len+1,maxlen,sum,maxsum);
    solve1(root->right,len+1,maxlen,sum,maxsum);

}
// Sum of nodes on the longest path
// Approch #2
int longestpathsum1(Node *root)
{
    int maxlen=0;
    int len =0;
    int sum =0;
    int maxsum;
    solve1(root,len,maxlen,sum,maxsum);
    return maxsum;
}
int main(int argc, char const *argv[])
{

    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    cout << "Approch #1 Sum of nodes on the longest path of Binary Tree 1 : " << longestpathsum(root)<<endl;
    cout << "Approch #2 Sum of nodes on the longest path of Binary Tree 1 : " << longestpathsum1(root)<<endl;
    cout << endl;

    // tree 2
    int data1[] = {1, 2, -1, -1, 5, 6, 8, -1, -1, -1, 7, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Approch #1 Sum of nodes on the longest path of Binary Tree 2 : " << longestpathsum(root1)<<endl;
    cout << "Approch #2 Sum of nodes on the longest path of Binary Tree 2 : " << longestpathsum1(root1)<<endl;
    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    cout << "Approch #1 Sum of nodes on the longest path of Binary Tree 3 : " << longestpathsum(root2)<<endl;
    cout << "Approch #2 Sum of nodes on the longest path of Binary Tree 3 : " << longestpathsum1(root2)<<endl;
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
