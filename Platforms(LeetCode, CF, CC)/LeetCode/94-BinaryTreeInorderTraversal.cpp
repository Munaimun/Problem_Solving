// ============================================================================
// Problem: Binary Tree Inorder Traversal
// Time Complexity: O(n)  — every node is visited once
// Space Complexity: O(n) — recursion stack + output array
//
// Description:
// Given the root of a binary tree, return its inorder traversal.
// Inorder traversal order: Left → Root → Right.
//
// This implementation uses a simple Depth-First Search (DFS) approach.
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    // DFS helper function for inorder traversal
    void dfs(TreeNode *root, vector<int> &ans)
    {
        // Base Case:
        // If the current node is NULL, there is nothing to process.
        // Simply return back to the previous recursive call.
        if (root == nullptr)
            return;

        // FIRST: Visit the LEFT subtree
        // This keeps going left until root->left becomes NULL.
        dfs(root->left, ans);

        // SECOND: Process the CURRENT NODE
        // We "visit" the node by storing its value in the vector.
        ans.push_back(root->val);


        // THIRD: Visit the RIGHT subtree
        dfs(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};