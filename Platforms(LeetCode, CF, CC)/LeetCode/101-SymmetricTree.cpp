// ============================================================================
// Problem: Symmetric Binary Tree
// Time Complexity: O(n) — every node is visited once
// Space Complexity: O(n) — recursion stack in worst-case (skewed tree)
//
// Description:
// A binary tree is symmetric if the left subtree is a mirror of the right subtree.
// We recursively compare:
//      left subtree  of r1   with   right subtree of r2
//      right subtree of r1   with   left subtree  of r2
//
// Core Idea:
// Two subtrees are mirrors if:
//   1. Their root values are equal
//   2. Left subtree mirrors right subtree
//   3. Right subtree mirrors left subtree
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

// ------------------------
// Tree Node Structure
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

// ----------------------------------------------------------
// Solution Class — checks if the binary tree is symmetric
// ----------------------------------------------------------
class Solution
{
public:

    // Helper DFS function to compare two nodes in a mirror fashion
    bool dfs(TreeNode *r1, TreeNode *r2)
    {
        // Case 1:
        // If BOTH nodes are NULL → they are symmetric at this point
        if (r1 == nullptr && r2 == nullptr)
            return true;

        // Case 2:
        // If only ONE of them is NULL → structure differs → not symmetric
        if (r1 == nullptr || r2 == nullptr)
            return false;

        // Case 3:
        // If values differ → not symmetric
        if (r1->val != r2->val)
            return false;

        // Now recursively check:
        // - left child of r1 with right child of r2
        // - right child of r1 with left child of r2
        //
        // This is the core MIRROR check.
        bool res1 = dfs(r1->left, r2->right);
        bool res2 = dfs(r1->right, r2->left);

        // Tree is symmetric only if BOTH sides match
        return (res1 && res2);
    }

    // Main function that starts the mirror check
    bool isSymmetric(TreeNode *root)
    {
        // If tree is empty, it's symmetric by default
        if (!root) return true;

        // Compare left and right subtrees
        return dfs(root->left, root->right);
    }
};