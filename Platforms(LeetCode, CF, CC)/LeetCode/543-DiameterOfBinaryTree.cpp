// ===============================================
// Problem: Diameter of Binary Tree
// 
// Given a binary tree, find the length of the longest path between any two nodes.
// The path may or may not pass through the root.
//
// Time Complexity: O(n)
//   - Each node is visited exactly once.
//
// Space Complexity: O(h)
//   - h = height of tree (stack space for recursion)
//   - Worst case: O(n) skewed tree
//   - Best case: O(log n) balanced tree
// ===============================================

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------
// Definition for a binary tree node
// -----------------------------------------------
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

class Solution
{
    // ------------------------------------------------------------
    // dfs(root, ans):
    // Computes the height of subtree rooted at `root`.
    // Also updates `ans` to store the largest diameter seen so far.
    //
    // leftDepth  = height of left subtree
    // rightDept  = height of right subtree
    //
    // Diameter through current node = leftDepth + rightDepth + 1 (number of nodes)
    //
    // Returns: height of the current subtree
    // ------------------------------------------------------------
    int dfs(TreeNode *root, int &ans)
    {
        if(root == nullptr) return 0; // Base case: empty node has height 0

        // Recursively compute heights of left and right subtrees
        int leftDepth = dfs(root->left, ans);
        int rightDept = dfs(root->right, ans);

        // Update the maximum diameter seen so far
        ans = max(ans, leftDepth + rightDept + 1);

        // Return height of current subtree (count this node)
        return max(leftDepth, rightDept) + 1;
    }

public:
    // ------------------------------------------------------------
    // diameterOfBinaryTree(root):
    // Wrapper function that calls dfs to compute the diameter.
    // Returns diameter in terms of edges (LeetCode convention)
    // ------------------------------------------------------------
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans - 1; // Convert from node count to edge count
    }
};