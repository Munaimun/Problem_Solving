// ------------------------------------------------------------
// Problem: Lowest Common Ancestor of a Binary Tree
// Time Complexity: O(N) — every node is visited once in DFS
// Space Complexity: O(H) — recursion stack height (H = tree height)
// ------------------------------------------------------------
//
// Intuition:
// We want to find the lowest (deepest) node that has both p and q
// in its subtree. Using DFS, we check left and right subtrees.
//
// If the current root is:
//  - nullptr → no node here
//  - p or q  → one target found
//
// After searching both sides:
//  - If both left and right returned non-null, current root is LCA.
//  - Otherwise return whichever side is non-null.
//
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// Basic TreeNode structure
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
    // Depth-First Search helper
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: no node OR one of the targets found
        if (root == nullptr || root == p || root == q)
            return root;

        // Explore left and right subtrees
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        // If both sides return nodes, current root is LCA
        if (left != nullptr && right != nullptr)
            return root;

        // Otherwise return the non-null result
        return (left != nullptr) ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
