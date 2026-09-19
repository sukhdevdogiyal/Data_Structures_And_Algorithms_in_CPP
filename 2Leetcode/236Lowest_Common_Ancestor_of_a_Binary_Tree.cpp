// 236. Lowest Common Ancestor of a Binary Tree

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


// Method 1: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(h)


// Method 2: Parent Mapping + Iterative
// Time Complexity: O(n)
// Space Complexity: O(n)


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
// METHOD 1: RECURSIVE DFS
// =====================================================

TreeNode* lowestCommonAncestor(
    TreeNode* root,
    TreeNode* p,
    TreeNode* q
) {

    // Base case
    if(root == nullptr)
        return nullptr;


    // Root itself is p or q
    if(root == p || root == q)
        return root;


    // Search in left subtree
    TreeNode* left = lowestCommonAncestor(
        root->left,
        p,
        q
    );


    // Search in right subtree
    TreeNode* right = lowestCommonAncestor(
        root->right,
        p,
        q
    );


    // p and q are present in different subtrees
    if(left != nullptr && right != nullptr)
        return root;


    // If only one side has a result,
    // return that result
    if(left != nullptr)
        return left;

    return right;
}


// =====================================================
// METHOD 2: PARENT MAPPING + ITERATIVE
// =====================================================

TreeNode* lowestCommonAncestorParent(
    TreeNode* root,
    TreeNode* p,
    TreeNode* q
) {

    unordered_map<TreeNode*, TreeNode*> parent;

    vector<TreeNode*> stack;


    // Root has no parent
    parent[root] = nullptr;

    stack.push_back(root);


    // Build parent mapping
    while(!stack.empty()) {

        TreeNode* curr = stack.back();
        stack.pop_back();


        if(curr->left != nullptr) {

            parent[curr->left] = curr;

            stack.push_back(curr->left);
        }


        if(curr->right != nullptr) {

            parent[curr->right] = curr;

            stack.push_back(curr->right);
        }
    }


    // Store all ancestors of p
    unordered_set<TreeNode*> ancestors;


    TreeNode* curr = p;

    while(curr != nullptr) {

        ancestors.insert(curr);

        curr = parent[curr];
    }


    // Move upward from q
    // First common ancestor is LCA
    curr = q;

    while(ancestors.find(curr) == ancestors.end()) {

        curr = parent[curr];
    }


    return curr;
}


// =====================================================
// MAIN
// =====================================================

int main() {


    // ================= CASE 1 =================
    //
    // Tree:
    //
    //             3
    //            / \
    //           5   1
    //          / \ / \
    //         6  2 0  8
    //           / \
    //          7   4
    //
    // p = 5
    // q = 1
    //
    // Expected LCA = 3


    TreeNode* root1 = new TreeNode(3);

    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);

    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);

    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);

    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);


    TreeNode* p1 = root1->left;
    TreeNode* q1 = root1->right;


    cout << "Case 1 - Method 1: "
         << lowestCommonAncestor(root1, p1, q1)->val
         << endl;


    cout << "Case 1 - Method 2: "
         << lowestCommonAncestorParent(root1, p1, q1)->val
         << endl << endl;



    // ================= CASE 2 =================
    //
    // Same Tree
    //
    // p = 5
    // q = 4
    //
    // Expected LCA = 5


    TreeNode* root2 = new TreeNode(3);

    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);

    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(2);

    root2->right->left = new TreeNode(0);
    root2->right->right = new TreeNode(8);

    root2->left->right->left = new TreeNode(7);
    root2->left->right->right = new TreeNode(4);


    TreeNode* p2 = root2->left;
    TreeNode* q2 = root2->left->right->right;


    cout << "Case 2 - Method 1: "
         << lowestCommonAncestor(root2, p2, q2)->val
         << endl;


    cout << "Case 2 - Method 2: "
         << lowestCommonAncestorParent(root2, p2, q2)->val
         << endl << endl;



    // ================= CASE 3 =================
    //
    // Tree:
    //
    //          1
    //         / \
    //        2   3
    //
    // p = 2
    // q = 3
    //
    // Expected LCA = 1


    TreeNode* root3 = new TreeNode(1);

    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);


    TreeNode* p3 = root3->left;
    TreeNode* q3 = root3->right;


    cout << "Case 3 - Method 1: "
         << lowestCommonAncestor(root3, p3, q3)->val
         << endl;


    cout << "Case 3 - Method 2: "
         << lowestCommonAncestorParent(root3, p3, q3)->val
         << endl;


    return 0;
}