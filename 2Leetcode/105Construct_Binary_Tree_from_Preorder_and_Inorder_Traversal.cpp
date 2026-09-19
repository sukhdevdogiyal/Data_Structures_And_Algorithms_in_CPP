// 105. Construct Binary Tree from Preorder and Inorder Traversal

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


// Method 1: Recursive DFS + Linear Search
// Time Complexity: O(n^2)
// Space Complexity: O(h)

// Method 2: Recursive DFS + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)


#include <iostream>
#include <vector>
#include <unordered_map>

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
// METHOD 1: RECURSIVE DFS + LINEAR SEARCH
// =====================================================

TreeNode* solve(
    vector<int>& preorder,
    vector<int>& inorder,
    int& i,
    int s,
    int e
) {

    // Preorder finished
    // or current range is invalid
    if(i == preorder.size() || s > e)
        return nullptr;


    // Preorder gives the root
    int val = preorder[i++];

    TreeNode* root = new TreeNode(val);


    // Find root position in inorder
    int p = s;

    for(int j = s; j <= e; j++) {

        if(inorder[j] == val) {
            p = j;
            break;
        }
    }


    // Left subtree
    root->left = solve(
        preorder,
        inorder,
        i,
        s,
        p - 1
    );


    // Right subtree
    root->right = solve(
        preorder,
        inorder,
        i,
        p + 1,
        e
    );


    return root;
}


TreeNode* buildTree(
    vector<int>& preorder,
    vector<int>& inorder
) {

    int i = 0;

    return solve(
        preorder,
        inorder,
        i,
        0,
        inorder.size() - 1
    );
}


// =====================================================
// METHOD 2: RECURSIVE DFS + HASH MAP
// =====================================================

TreeNode* solveOptimized(
    vector<int>& preorder,
    unordered_map<int, int>& position,
    int& i,
    int s,
    int e
) {

    // Preorder finished
    // or current range is invalid
    if(i == preorder.size() || s > e)
        return nullptr;


    // Preorder gives the root
    int val = preorder[i++];

    TreeNode* root = new TreeNode(val);


    // Hash map se inorder mein root ki position
    // directly mil jayegi
    int p = position[val];


    // Left subtree
    root->left = solveOptimized(
        preorder,
        position,
        i,
        s,
        p - 1
    );


    // Right subtree
    root->right = solveOptimized(
        preorder,
        position,
        i,
        p + 1,
        e
    );


    return root;
}


TreeNode* buildTreeOptimized(
    vector<int>& preorder,
    vector<int>& inorder
) {

    unordered_map<int, int> position;


    // Inorder ke har element ki position store karo
    for(int i = 0; i < inorder.size(); i++) {
        position[inorder[i]] = i;
    }


    int i = 0;


    return solveOptimized(
        preorder,
        position,
        i,
        0,
        inorder.size() - 1
    );
}


// =====================================================
// PRINT TREE
// =====================================================

void printTree(TreeNode* root) {

    if(root == nullptr) {
        cout << "Empty";
        return;
    }


    // Level Order Traversal
    vector<TreeNode*> q;

    q.push_back(root);

    int front = 0;


    while(front < q.size()) {

        TreeNode* curr = q[front++];

        if(curr != nullptr) {

            cout << curr->val << " ";

            q.push_back(curr->left);
            q.push_back(curr->right);
        }
    }
}


// =====================================================
// MAIN
// =====================================================

int main() {


    // ================= CASE 1 =================
    //
    // Preorder:
    // [3, 9, 20, 15, 7]
    //
    // Inorder:
    // [9, 3, 15, 20, 7]
    //
    // Tree:
    //
    //          3
    //         / \
    //        9   20
    //           /  \
    //          15   7
    //
    // Expected:
    // 3 9 20 15 7


    vector<int> preorder1 = {
        3, 9, 20, 15, 7
    };

    vector<int> inorder1 = {
        9, 3, 15, 20, 7
    };


    TreeNode* root1 = buildTree(
        preorder1,
        inorder1
    );


    cout << "Case 1 - Method 1: ";

    printTree(root1);

    cout << endl;


    // Method 2 ke liye fresh input

    vector<int> preorder1_2 = {
        3, 9, 20, 15, 7
    };

    vector<int> inorder1_2 = {
        9, 3, 15, 20, 7
    };


    TreeNode* root1_2 = buildTreeOptimized(
        preorder1_2,
        inorder1_2
    );


    cout << "Case 1 - Method 2: ";

    printTree(root1_2);

    cout << endl << endl;


    // ================= CASE 2 =================
    //
    // Preorder:
    // [1, 2, 4, 5, 3]
    //
    // Inorder:
    // [4, 2, 5, 1, 3]
    //
    // Tree:
    //
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5
    //
    // Expected:
    // 1 2 3 4 5


    vector<int> preorder2 = {
        1, 2, 4, 5, 3
    };

    vector<int> inorder2 = {
        4, 2, 5, 1, 3
    };


    TreeNode* root2 = buildTree(
        preorder2,
        inorder2
    );


    cout << "Case 2 - Method 1: ";

    printTree(root2);

    cout << endl;


    // Method 2 ke liye fresh input

    vector<int> preorder2_2 = {
        1, 2, 4, 5, 3
    };

    vector<int> inorder2_2 = {
        4, 2, 5, 1, 3
    };


    TreeNode* root2_2 = buildTreeOptimized(
        preorder2_2,
        inorder2_2
    );


    cout << "Case 2 - Method 2: ";

    printTree(root2_2);

    cout << endl << endl;


    // ================= CASE 3 =================
    //
    // Preorder:
    // [1, 2, 3]
    //
    // Inorder:
    // [2, 1, 3]
    //
    // Tree:
    //
    //        1
    //       / \
    //      2   3
    //
    // Expected:
    // 1 2 3


    vector<int> preorder3 = {
        1, 2, 3
    };

    vector<int> inorder3 = {
        2, 1, 3
    };


    TreeNode* root3 = buildTree(
        preorder3,
        inorder3
    );


    cout << "Case 3 - Method 1: ";

    printTree(root3);

    cout << endl;


    // Method 2 ke liye fresh input

    vector<int> preorder3_2 = {
        1, 2, 3
    };

    vector<int> inorder3_2 = {
        2, 1, 3
    };


    TreeNode* root3_2 = buildTreeOptimized(
        preorder3_2,
        inorder3_2
    );


    cout << "Case 3 - Method 2: ";

    printTree(root3_2);

    cout << endl;


    return 0;
}