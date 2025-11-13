// Problem Statement:
// Given the root of a binary tree, return its preorder traversal.
// In preorder traversal, nodes are visited in this order:
// Root node
// Left subtree
// Right subtree

// Time Complexity: O(n) — every node is visited exactly once.
// Space Complexity: O(n) — due to recursion stack and output vector.

#include <bits/stdc++.h>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    // Helper DFS function to perform preorder traversal
    void dfs(TreeNode *root, vector<int> &ans) {
        if (root == nullptr)
            return; // Base case: stop when node is null

        ans.push_back(root->val);  // Step 1: Visit the root
        dfs(root->left, ans);      // Step 2: Recur on the left subtree
        dfs(root->right, ans);     // Step 3: Recur on the right subtree
    }

public:
    // Main function that returns preorder traversal of the binary tree
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};


int main() {
    /*
        Construct the following binary tree:

                1
                 \
                  2
                 /
                3

        Preorder Traversal: [1, 2, 3]
    */

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}