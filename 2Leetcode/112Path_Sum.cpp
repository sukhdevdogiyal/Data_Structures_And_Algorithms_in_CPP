// 112. Path Sum

// https://leetcode.com/problems/path-sum/

// Method 1: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(h)

// Method 2: Iterative DFS using Stack
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
#include <vector>
#include <stack>

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

bool hasPathSum(TreeNode* root, int targetSum) {

    if(root == nullptr)
        return false;

    // Leaf node
    if(root->left == nullptr && root->right == nullptr)
        return targetSum == root->val;

    // Remaining sum after current node
    bool left = hasPathSum(root->left, targetSum - root->val);

    bool right = hasPathSum(root->right, targetSum - root->val);

    return left || right;
}


// =====================================================
// METHOD 2: ITERATIVE DFS USING STACK
// =====================================================

bool hasPathSumIterative(TreeNode* root, int targetSum) {

    if(root == nullptr)
        return false;

    stack<pair<TreeNode*, int>> st;

    st.push({root, targetSum});

    while(!st.empty()) {

        TreeNode* current = st.top().first;
        int remaining = st.top().second;

        st.pop();

        // Leaf node
        if(current->left == nullptr && current->right == nullptr) {

            if(remaining == current->val)
                return true;
        }

        // Left child
        if(current->left != nullptr) {

            st.push({
                current->left,
                remaining - current->val
            });
        }

        // Right child
        if(current->right != nullptr) {

            st.push({
                current->right,
                remaining - current->val
            });
        }
    }

    return false;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================
    //
    //          5
    //         / \
    //        4   8
    //       /   / \
    //      11  13  4
    //     /  \      \
    //    7    2      1
    //
    // Target = 22
    //
    // Path: 5 -> 4 -> 11 -> 2 = 22
    //
    // Expected: true

    TreeNode* root1 = new TreeNode(5);

    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);

    root1->left->left = new TreeNode(11);

    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);

    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);

    root1->right->right->right = new TreeNode(1);

    int target1 = 22;


    cout << boolalpha;

    cout << "Case 1 - Method 1: "
         << hasPathSum(root1, target1)
         << endl;


    // Fresh tree for Method 2

    TreeNode* root1_2 = new TreeNode(5);

    root1_2->left = new TreeNode(4);
    root1_2->right = new TreeNode(8);

    root1_2->left->left = new TreeNode(11);

    root1_2->left->left->left = new TreeNode(7);
    root1_2->left->left->right = new TreeNode(2);

    root1_2->right->left = new TreeNode(13);
    root1_2->right->right = new TreeNode(4);

    root1_2->right->right->right = new TreeNode(1);


    cout << "Case 1 - Method 2: "
         << hasPathSumIterative(root1_2, target1)
         << endl;


    // ================= CASE 2 =================
    //
    //        1
    //       / \
    //      2   3
    //
    // Target = 5
    //
    // Path: 1 -> 2 = 3
    //       1 -> 3 = 4
    //
    // Expected: false

    TreeNode* root2 = new TreeNode(1);

    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    int target2 = 5;


    cout << "Case 2 - Method 1: "
         << hasPathSum(root2, target2)
         << endl;


    // Fresh tree for Method 2

    TreeNode* root2_2 = new TreeNode(1);

    root2_2->left = new TreeNode(2);
    root2_2->right = new TreeNode(3);


    cout << "Case 2 - Method 2: "
         << hasPathSumIterative(root2_2, target2)
         << endl;


    // ================= CASE 3 =================
    //
    //        1
    //
    // Target = 1
    //
    // Expected: true

    TreeNode* root3 = new TreeNode(1);

    int target3 = 1;


    cout << "Case 3 - Method 1: "
         << hasPathSum(root3, target3)
         << endl;


    TreeNode* root3_2 = new TreeNode(1);

    cout << "Case 3 - Method 2: "
         << hasPathSumIterative(root3_2, target3)
         << endl;


    return 0;
}