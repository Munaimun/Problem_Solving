// ===============================================
// Problem: Maximum Depth of Binary Tree
//
// Time Complexity:  O(n)
//   - We visit every node exactly once.
//
// Space Complexity: O(h)
//   - Where h is the height of the tree (stack space for recursion).
//   - Worst case: O(n) for a skewed tree.
//   - Best case: O(log n) for a balanced tree.
// ===============================================

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------
// Definition of a tree node. Each node contains:
// val  -> the integer value
// left -> pointer to left child
// right -> pointer to right child
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
    // dfs(root):
    // Computes the maximum depth of the subtree rooted at `root`.
    //
    // Base Case:
    //   - If root is nullptr, depth is 0.
    //
    // Recursive Idea:
    //   - Depth at this node = 1 (for current node)
    //       + max(depth of left subtree, depth of right subtree)
    // ------------------------------------------------------------
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0; // No node → depth = 0

        // Explore left and right subtrees recursively
        int left = 1 + dfs(root->left);
        int right = 1 + dfs(root->right);

        // Take whichever side gives the larger depth
        return max(left, right);
    }

public:
    // Wrapper method that starts the DFS
    int maxDepth(TreeNode *root)
    {
        return dfs(root);
    }
};
