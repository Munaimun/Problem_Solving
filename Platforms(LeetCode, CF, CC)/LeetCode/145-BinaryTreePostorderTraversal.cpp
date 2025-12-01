// ============================================================================
// Problem: Binary Tree Postorder Traversal
// Time Complexity: O(n)  — each node is visited exactly once
// Space Complexity: O(n) — recursion stack + output array
//
// Description:
// Given the root of a binary tree, return its postorder traversal.
// Postorder traversal order: Left → Right → Root.
//
// This implementation uses Depth-First Search (DFS) recursion.
// The logic ensures that child nodes are processed BEFORE the parent.
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

// ------------------------
// Binary Tree Node Structure
// ------------------------
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// -----------------------------------------------
// Solution Class — handles postorder traversal
// -----------------------------------------------
class Solution
{
public:

    // DFS helper for postorder traversal
    // We pass `ans` by reference so all recursive calls write
    // to the same vector without copying.
    void dfs(TreeNode *root, vector<int> &ans)
    {
        // Base Case:
        // If the node is NULL, there's nothing to process.
        if (root == nullptr) return;

        // ---------------------------------------------------------
        // POSTORDER TRAVERSAL = Left → Right → Root
        // ---------------------------------------------------------

        // FIRST: Visit the LEFT subtree
        dfs(root->left, ans);

        // SECOND: Visit the RIGHT subtree
        dfs(root->right, ans);

        // THIRD: Process the CURRENT node (Root)
        // Push the value at the END, after children are processed.
        ans.push_back(root->val);
    }

    // Main function that returns postorder traversal
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        dfs(root, ans);

        return ans;
    }
};
