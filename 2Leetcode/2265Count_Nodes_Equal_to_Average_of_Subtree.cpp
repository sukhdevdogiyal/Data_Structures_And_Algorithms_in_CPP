// 2265. Count Nodes Equal to Average of Subtree

// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

// Method 1: Postorder Traversal + Pair
// Time Complexity: O(n)
// Space Complexity: O(h)

// Method 2: Postorder Traversal + Array
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};


// =====================================================
// METHOD 1: POSTORDER + PAIR
// =====================================================

// pair.first  = number of nodes
// pair.second = sum of nodes

pair<int, int> solve(TreeNode* root, int& ans) {

    // Leaf node
    if(root->left == nullptr && root->right == nullptr) {

        ans++;

        return make_pair(1, root->val);
    }

    pair<int, int> left = make_pair(0, 0);
    pair<int, int> right = make_pair(0, 0);

    if(root->left)
        left = solve(root->left, ans);

    if(root->right)
        right = solve(root->right, ans);

    int n1 = left.first;
    int n2 = right.first;

    int sum1 = left.second;
    int sum2 = right.second;

    // Current subtree ka total sum
    int total = sum1 + sum2 + root->val;

    // Current subtree mein total nodes
    int n = n1 + n2 + 1;

    // Integer division automatically floor karega
    int avg = total / n;

    // Average == root value
    if(avg == root->val)
        ans++;

    return make_pair(n, total);
}


int averageOfSubtree(vector<int>& dummy) {
    return 0;
}


// =====================================================
// METHOD 2: POSTORDER + ARRAY
// =====================================================

// result[0] = number of nodes
// result[1] = sum

vector<int> solveOptimized(TreeNode* root, int& ans) {

    if(root == nullptr)
        return {0, 0};

    vector<int> left = solveOptimized(root->left, ans);
    vector<int> right = solveOptimized(root->right, ans);

    int count = left[0] + right[0] + 1;
    int sum = left[1] + right[1] + root->val;

    int avg = sum / count;

    if(avg == root->val)
        ans++;

    return {count, sum};
}


int averageOfSubtreeOptimized(TreeNode* root) {

    if(root == nullptr)
        return 0;

    int ans = 0;

    solveOptimized(root, ans);

    return ans;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================
    //
    //          4
    //        /   \
    //       8     5
    //      / \     \
    //     0   1     6
    //
    // Answer = 5

    TreeNode* root1 = new TreeNode(4);

    root1->left = new TreeNode(8);
    root1->right = new TreeNode(5);

    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(1);

    root1->right->right = new TreeNode(6);

    int ans1 = 0;

    solve(root1, ans1);

    cout << "Case 1 - Method 1: "
         << ans1 << endl;

    cout << "Case 1 - Method 2: "
         << averageOfSubtreeOptimized(root1)
         << endl;


    // ================= CASE 2 =================
    //
    //       1
    //
    // Answer = 1

    TreeNode* root2 = new TreeNode(1);

    int ans2 = 0;

    solve(root2, ans2);

    cout << "Case 2 - Method 1: "
         << ans2 << endl;

    cout << "Case 2 - Method 2: "
         << averageOfSubtreeOptimized(root2)
         << endl;


    return 0;
}