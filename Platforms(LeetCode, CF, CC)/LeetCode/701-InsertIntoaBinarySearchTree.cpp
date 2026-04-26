// Problem:
// Insert a value into a Binary Search Tree (BST) and return the root of the updated tree.
//
// A BST follows these rules:
// 1. Left subtree contains values < node value
// 2. Right subtree contains values > node value
//
// Approach:
// - Start from the root
// - Traverse the tree iteratively
// - Move left or right depending on the value
// - Insert the new node when a NULL position is found
//
// Time Complexity:
// - Average Case: O(log n)
// - Worst Case (skewed tree): O(n)
//
// Space Complexity:
// - O(1) (iterative approach, no recursion stack)

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize node
    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If tree is empty, create and return new node
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Start traversal from root
        TreeNode* cur = root;

        while (true) {

            // Case 1: Go to left subtree
            if (val < cur->val) {

                // If left child is empty → insert here
                if (cur->left == nullptr) {
                    cur->left = new TreeNode(val);
                    break; // insertion done
                }

                // Otherwise, keep moving left
                cur = cur->left;
            }

            // Case 2: Go to right subtree
            else {

                // If right child is empty → insert here
                if (cur->right == nullptr) {
                    cur->right = new TreeNode(val);
                    break; // insertion done
                }

                // Otherwise, keep moving right
                cur = cur->right;
            }
        }

        // Return original root (tree is modified in-place)
        return root;
    }
};