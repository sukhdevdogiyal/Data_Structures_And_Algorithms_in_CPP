// 106. Construct Binary Tree from Inorder and Postorder Traversal

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


// Method 1: Recursive DFS + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)


// Method 2: Recursive DFS + Linear Search
// Time Complexity: O(n^2)
// Space Complexity: O(h)


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
// METHOD 1: RECURSIVE DFS + HASH MAP
// =====================================================

TreeNode* solve(
    vector<int>& inorder,
    vector<int>& postorder,
    unordered_map<int, int>& position,
    int& index,
    int s,
    int e
) {

    // Postorder finished
    // or current range is invalid
    if(index < 0 || s > e)
        return nullptr;


    // Postorder ka last element root hota hai
    int val = postorder[index--];

    TreeNode* root = new TreeNode(val);


    // Inorder mein root ki position
    int p = position[val];


    // Postorder ko reverse direction mein process
    // kar rahe hain, isliye RIGHT subtree pehle banega
    root->right = solve(
        inorder,
        postorder,
        position,
        index,
        p + 1,
        e
    );


    // Uske baad LEFT subtree
    root->left = solve(
        inorder,
        postorder,
        position,
        index,
        s,
        p - 1
    );


    return root;
}


TreeNode* buildTree(
    vector<int>& inorder,
    vector<int>& postorder
) {

    unordered_map<int, int> position;

    int n = inorder.size();


    // Inorder ke elements ki positions store karo
    for(int i = 0; i < n; i++) {
        position[inorder[i]] = i;
    }


    // Postorder ka last element root hota hai
    int index = n - 1;


    return solve(
        inorder,
        postorder,
        position,
        index,
        0,
        n - 1
    );
}


// =====================================================
// METHOD 2: RECURSIVE DFS + LINEAR SEARCH
// =====================================================

TreeNode* solveLinear(
    vector<int>& inorder,
    vector<int>& postorder,
    int& index,
    int s,
    int e
) {

    // Postorder finished
    // or current range is invalid
    if(index < 0 || s > e)
        return nullptr;


    // Postorder ka last element root
    int val = postorder[index--];

    TreeNode* root = new TreeNode(val);


    // Inorder mein root ki position find karo
    int p = s;

    for(int j = s; j <= e; j++) {

        if(inorder[j] == val) {
            p = j;
            break;
        }
    }


    // Reverse postorder ke karan
    // RIGHT subtree pehle
    root->right = solveLinear(
        inorder,
        postorder,
        index,
        p + 1,
        e
    );


    // LEFT subtree baad mein
    root->left = solveLinear(
        inorder,
        postorder,
        index,
        s,
        p - 1
    );


    return root;
}


TreeNode* buildTreeLinear(
    vector<int>& inorder,
    vector<int>& postorder
) {

    int index = postorder.size() - 1;


    return solveLinear(
        inorder,
        postorder,
        index,
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
    // Inorder:
    // [9, 3, 15, 20, 7]
    //
    // Postorder:
    // [9, 15, 7, 20, 3]
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


    vector<int> inorder1 = {
        9, 3, 15, 20, 7
    };

    vector<int> postorder1 = {
        9, 15, 7, 20, 3
    };


    TreeNode* root1 = buildTree(
        inorder1,
        postorder1
    );


    cout << "Case 1 - Method 1: ";

    printTree(root1);

    cout << endl;


    // Method 2 ke liye fresh input

    vector<int> inorder1_2 = {
        9, 3, 15, 20, 7
    };

    vector<int> postorder1_2 = {
        9, 15, 7, 20, 3
    };


    TreeNode* root1_2 = buildTreeLinear(
        inorder1_2,
        postorder1_2
    );


    cout << "Case 1 - Method 2: ";

    printTree(root1_2);

    cout << endl << endl;


    // ================= CASE 2 =================
    //
    // Inorder:
    // [4, 2, 5, 1, 3]
    //
    // Postorder:
    // [4, 5, 2, 3, 1]
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


    vector<int> inorder2 = {
        4, 2, 5, 1, 3
    };

    vector<int> postorder2 = {
        4, 5, 2, 3, 1
    };


    TreeNode* root2 = buildTree(
        inorder2,
        postorder2
    );


    cout << "Case 2 - Method 1: ";

    printTree(root2);

    cout << endl;


    // Method 2 ke liye fresh input

    vector<int> inorder2_2 = {
        4, 2, 5, 1, 3
    };

    vector<int> postorder2_2 = {
        4, 5, 2, 3, 1
    };


    TreeNode* root2_2 = buildTreeLinear(
        inorder2_2,
        postorder2_2
    );


    cout << "Case 2 - Method 2: ";

    printTree(root2_2);

    cout << endl << endl;


    // ================= CASE 3 =================
    //
    // Inorder:
    // [2, 1, 3]
    //
    // Postorder:
    // [2, 3, 1]
    //
    // Tree:
    //
    //        1
    //       / \
    //      2   3
    //
    // Expected:
    // 1 2 3


    vector<int> inorder3 = {
        2, 1, 3
    };

    vector<int> postorder3 = {
        2, 3, 1
    };


    TreeNode* root3 = buildTree(
        inorder3,
        postorder3
    );


    cout << "Case 3 - Method 1: ";

    printTree(root3);

    cout << endl;


    // Method 2 ke liye fresh input

    vector<int> inorder3_2 = {
        2, 1, 3
    };

    vector<int> postorder3_2 = {
        2, 3, 1
    };


    TreeNode* root3_2 = buildTreeLinear(
        inorder3_2,
        postorder3_2
    );


    cout << "Case 3 - Method 2: ";

    printTree(root3_2);

    cout << endl;


    return 0;
}