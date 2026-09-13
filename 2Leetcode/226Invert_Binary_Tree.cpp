// 226. Invert Binary Tree

// https://leetcode.com/problems/invert-binary-tree/

// Method 1: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(h)

// Method 2: Iterative BFS using Queue
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <queue>

using namespace std;

// =====================================================
// TREE NODE
// =====================================================

struct TreeNode {
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
// METHOD 1: RECURSIVE DFS
// =====================================================

TreeNode* invertTree(TreeNode* root) {

    if(root == nullptr)
        return root;

    // Save original left child
    TreeNode* left = root->left;

    // Right subtree becomes left
    root->left = invertTree(root->right);

    // Original left subtree becomes right
    root->right = invertTree(left);

    return root;
}


// =====================================================
// METHOD 2: ITERATIVE BFS
// =====================================================

TreeNode* invertTreeBFS(TreeNode* root) {

    if(root == nullptr)
        return root;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        // Swap left and right
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;

        // Process left subtree
        if(current->left != nullptr)
            q.push(current->left);

        // Process right subtree
        if(current->right != nullptr)
            q.push(current->right);
    }

    return root;
}


// =====================================================
// PRINT TREE - LEVEL ORDER
// =====================================================

void printTree(TreeNode* root) {

    if(root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if(current->left)
            q.push(current->left);

        if(current->right)
            q.push(current->right);
    }

    cout << endl;
}

// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================
    //
    //        4
    //       / \
    //      2   7
    //     / \ / \
    //    1  3 6  9

    TreeNode* root1 = new TreeNode(4);

    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);

    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);


    // Method 1
    TreeNode* result1 = invertTree(root1);

    cout << "Case 1 - Method 1: ";
    printTree(result1);


    // Case 1 ke liye tree dobara banayenge
    // kyunki Method 1 ne original tree modify kar diya hai

    TreeNode* root1_2 = new TreeNode(4);

    root1_2->left = new TreeNode(2);
    root1_2->right = new TreeNode(7);

    root1_2->left->left = new TreeNode(1);
    root1_2->left->right = new TreeNode(3);

    root1_2->right->left = new TreeNode(6);
    root1_2->right->right = new TreeNode(9);


    // Method 2
    TreeNode* result1_2 = invertTreeBFS(root1_2);

    cout << "Case 1 - Method 2: ";
    printTree(result1_2);


    // ================= CASE 2 =================
    //
    //       2
    //      / \
    //     1   3

    TreeNode* root2 = new TreeNode(2);

    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);


    // Method 1
    TreeNode* result2 = invertTree(root2);

    cout << "Case 2 - Method 1: ";
    printTree(result2);


    // Case 2 ke liye tree dobara banayenge

    TreeNode* root2_2 = new TreeNode(2);

    root2_2->left = new TreeNode(1);
    root2_2->right = new TreeNode(3);


    // Method 2
    TreeNode* result2_2 = invertTreeBFS(root2_2);

    cout << "Case 2 - Method 2: ";
    printTree(result2_2);


    return 0;
}