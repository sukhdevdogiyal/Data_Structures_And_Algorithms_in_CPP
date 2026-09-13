// 572. Subtree of Another Tree

// https://leetcode.com/problems/subtree-of-another-tree/

// Method 1: Recursive DFS + Same Tree
// Time Complexity: O(m * n)
// Space Complexity: O(h)

// Method 2: Serialization + String Search
// Time Complexity: O(m + n)
// Space Complexity: O(m + n)

#include <iostream>
#include <string>

using namespace std;


// =====================================================
// TREE NODE
// =====================================================

class TreeNode {
public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


// =====================================================
// METHOD 1: RECURSIVE DFS + SAME TREE
// =====================================================

bool sameTree(TreeNode* root, TreeNode* subRoot) {

    // Both are NULL
    if(root == nullptr && subRoot == nullptr)
        return true;

    // One is NULL and other is not
    if(root == nullptr || subRoot == nullptr)
        return false;

    // Values are different
    if(root->val != subRoot->val)
        return false;

    bool left = sameTree(root->left, subRoot->left);

    bool right = sameTree(root->right, subRoot->right);

    return left && right;
}


bool isSubtree(TreeNode* root, TreeNode* subRoot) {

    // Empty subtree is always a subtree
    if(subRoot == nullptr)
        return true;

    // Main tree finished but subtree still exists
    if(root == nullptr)
        return false;

    // Check current node
    bool curr = sameTree(root, subRoot);

    // Search in left subtree
    bool left = isSubtree(root->left, subRoot);

    // Search in right subtree
    bool right = isSubtree(root->right, subRoot);

    return curr || left || right;
}


// =====================================================
// METHOD 2: SERIALIZATION
// =====================================================

void serialize(TreeNode* root, string& ans) {

    if(root == nullptr) {
        ans += "#,";
        return;
    }

    ans += to_string(root->val);
    ans += ",";

    serialize(root->left, ans);
    serialize(root->right, ans);
}


bool isSubtreeSerialization(TreeNode* root, TreeNode* subRoot) {

    string mainTree = "";
    string subTree = "";

    serialize(root, mainTree);
    serialize(subRoot, subTree);

    return mainTree.find(subTree) != string::npos;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================
    //
    // Main Tree:
    //
    //          3
    //         / \
    //        4   5
    //       / \
    //      1   2
    //
    // SubTree:
    //
    //        4
    //       / \
    //      1   2
    //
    // Expected: true


    TreeNode* root1 = new TreeNode(3);

    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);

    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);


    TreeNode* subRoot1 = new TreeNode(4);

    subRoot1->left = new TreeNode(1);
    subRoot1->right = new TreeNode(2);


    cout << boolalpha;

    cout << "Case 1 - Method 1: "
         << isSubtree(root1, subRoot1)
         << endl;

    cout << "Case 1 - Method 2: "
         << isSubtreeSerialization(root1, subRoot1)
         << endl;


    // ================= CASE 2 =================
    //
    // Main Tree:
    //
    //          3
    //         / \
    //        4   5
    //       / \
    //      1   2
    //           \
    //            0
    //
    // SubTree:
    //
    //        4
    //       / \
    //      1   2
    //
    // Expected: false


    TreeNode* root2 = new TreeNode(3);

    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);

    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);

    root2->left->right->right = new TreeNode(0);


    TreeNode* subRoot2 = new TreeNode(4);

    subRoot2->left = new TreeNode(1);
    subRoot2->right = new TreeNode(2);


    cout << "Case 2 - Method 1: "
         << isSubtree(root2, subRoot2)
         << endl;

    cout << "Case 2 - Method 2: "
         << isSubtreeSerialization(root2, subRoot2)
         << endl;


    // ================= CASE 3 =================
    //
    // Main Tree:
    //
    //        1
    //       / \
    //      2   3
    //
    // SubTree:
    //
    //        2
    //
    // Expected: true


    TreeNode* root3 = new TreeNode(1);

    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);


    TreeNode* subRoot3 = new TreeNode(2);


    cout << "Case 3 - Method 1: "
         << isSubtree(root3, subRoot3)
         << endl;

    cout << "Case 3 - Method 2: "
         << isSubtreeSerialization(root3, subRoot3)
         << endl;


    return 0;
}