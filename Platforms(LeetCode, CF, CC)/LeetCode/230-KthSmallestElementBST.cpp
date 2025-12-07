// Problem: Kth Smallest Element in a BST
// Given the root of a Binary Search Tree (BST) and an integer k,
// return the k-th smallest value in the tree.

// Time Complexity: O(n)
// We perform an in-order traversal which visits each node exactly once.

// Space Complexity: O(n)
// We store the in-order traversal result in a vector.

// ---------------------------------------------------------------
// TreeNode definition
#include <bits/stdc++.h>
using namespace std;

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
    // In-order traversal helper
    // This visits nodes in sorted order for a BST.
    void inOrder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr)
            return;

        // inorder traversal: left->root->right
        inOrder(root->left, ans);        // Visit left subtree
        ans.push_back(root->val);        // Store current node
        inOrder(root->right, ans);       // Visit right subtree
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> ans;
        inOrder(root, ans);
        return ans[k - 1];
    }
};