// 124. Binary Tree Maximum Path Sum

// https://leetcode.com/problems/binary-tree-maximum-path-sum/


// Method 1: Recursive DFS + Global Maximum
// Time Complexity: O(n)
// Space Complexity: O(h)


// Method 2: Recursive DFS + Pair
// Time Complexity: O(n)
// Space Complexity: O(h)


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

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
// METHOD 1: RECURSIVE DFS + GLOBAL MAXIMUM
// =====================================================

int ans = INT_MIN;


int helper(TreeNode* node) {

    // Empty node contributes 0
    if(node == nullptr)
        return 0;


    // Negative path ko ignore kar do
    int left = max(helper(node->left), 0);

    int right = max(helper(node->right), 0);


    // Current node ko highest point maan kar
    // maximum path calculate karo
    ans = max(
        ans,
        node->val + left + right
    );


    // Parent ko sirf ek side ka path
    // return kar sakte hain
    return node->val + max(left, right);
}


int maxPathSum(TreeNode* root) {

    ans = INT_MIN;

    helper(root);

    return ans;
}


// =====================================================
// METHOD 2: RECURSIVE DFS + PAIR
// =====================================================

pair<int, int> helperPair(TreeNode* node) {

    // {maximum downward path, maximum path in subtree}
    if(node == nullptr)
        return {0, INT_MIN};


    pair<int, int> left = helperPair(node->left);

    pair<int, int> right = helperPair(node->right);


    // Negative downward paths ko ignore karo
    int leftGain = max(left.first, 0);
    int rightGain = max(right.first, 0);


    // Current node ke through complete path
    int currentPath =
        node->val + leftGain + rightGain;


    // Parent ko sirf ek direction ka path
    // de sakte hain
    int downwardPath =
        node->val + max(leftGain, rightGain);


    // Subtree ka maximum path
    int bestPath =
        max(currentPath, max(left.second, right.second));


    return {downwardPath, bestPath};
}


int maxPathSumPair(TreeNode* root) {

    return helperPair(root).second;
}


// =====================================================
// MAIN
// =====================================================

int main() {


    // ================= CASE 1 =================
    //
    // Tree:
    //
    //          1
    //         / \
    //        2   3
    //
    // Maximum Path:
    //
    //       2 -> 1 -> 3
    //
    // Expected: 6


    TreeNode* root1 = new TreeNode(1);

    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);


    cout << "Case 1 - Method 1: "
         << maxPathSum(root1)
         << endl;


    cout << "Case 1 - Method 2: "
         << maxPathSumPair(root1)
         << endl << endl;



    // ================= CASE 2 =================
    //
    // Tree:
    //
    //          -10
    //          /  \
    //         9    20
    //             /  \
    //            15   7
    //
    // Maximum Path:
    //
    //       15 -> 20 -> 7
    //
    // Expected: 42


    TreeNode* root2 = new TreeNode(-10);

    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);

    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);


    cout << "Case 2 - Method 1: "
         << maxPathSum(root2)
         << endl;


    cout << "Case 2 - Method 2: "
         << maxPathSumPair(root2)
         << endl << endl;



    // ================= CASE 3 =================
    //
    // Tree:
    //
    //          -3
    //
    // Maximum Path:
    //
    //          -3
    //
    // Expected: -3


    TreeNode* root3 = new TreeNode(-3);


    cout << "Case 3 - Method 1: "
         << maxPathSum(root3)
         << endl;


    cout << "Case 3 - Method 2: "
         << maxPathSumPair(root3)
         << endl;


    return 0;
}