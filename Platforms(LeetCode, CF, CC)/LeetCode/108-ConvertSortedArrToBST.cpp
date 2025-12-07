// -----------------------------------------------------------------------------
// Problem: Convert Sorted Array to Height-Balanced BST
// Time Complexity: O(N) — each element becomes a tree node exactly once
// Space Complexity: O(H) — recursion depth (H = height of tree, ~logN for balanced)
// -----------------------------------------------------------------------------
//
// Intuition:
// A BST built from a sorted array is balanced ONLY if we pick the middle element
// as the root. The left half becomes the left subtree, the right half becomes the
// right subtree. Recursively applying this ensures minimal height.
//
// Example:
// nums = [-10, -3, 0, 5, 9]
//
// mid = 2 → 0 becomes root
// Left half  = [-10, -3] → builds left subtree
// Right half = [5, 9]   → builds right subtree
//
// Final BST:
//          0
//        /   \
//     -10     5
//        \      \
//        -3      9
// -----------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// TreeNode structure representing each node of the BST
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
    // Recursive function to build BST from sorted array segment
    TreeNode* bst(vector<int>& nums, int left, int right) {
        // Base case: no elements left in this part of array
        if (left > right)
            return nullptr;

        // Pick the middle element as root to keep tree balanced
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left subtree (elements before mid)
        root->left = bst(nums, left, mid - 1);

        // Recursively build the right subtree (elements after mid)
        root->right = bst(nums, mid + 1, right);

        return root; // Return the constructed subtree
    }

public:
    // Main function called by user → builds BST using the full array range
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size() - 1);
    }
};