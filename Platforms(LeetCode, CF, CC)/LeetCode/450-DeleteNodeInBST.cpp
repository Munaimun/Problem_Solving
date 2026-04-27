// Problem Statement:
// ------------------
// Given the root of a Binary Search Tree (BST) and a key,
// delete the node with the given key and return the updated root.
//
// A BST has the property:
// - Left subtree values < root value
// - Right subtree values > root value
//
// While deleting a node, we must maintain this BST property.


// Time Complexity: O(h)
// - h = height of the tree
// - Best/Average (balanced tree): O(log n)
// - Worst (skewed tree): O(n)
//
// Space Complexity: O(h)
// - Due to recursion stack


#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};


class Solution {
private:
    // Helper function to find the minimum node in a subtree
    // (i.e., leftmost node)
    TreeNode* findMin(TreeNode* root){
        // Keep going left until we can't anymore
        while(root->left) {
            root = root->left;
        }
        return root;   
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // Base case: if tree is empty
        if(root == nullptr) return nullptr;

        // Step 1: Traverse the tree to find the node
        if(key < root->val) {
            // Key is smaller → go left
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            // Key is greater → go right
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node found

            // Case 1: No left child
            // Replace node with its right child
            if(root->left == nullptr) {
                return root->right;
            }

            // Case 2: No right child
            // Replace node with its left child
            else if(root->right == nullptr) {
                return root->left;
            }

            // Case 3: Node has TWO children
            else {
                // Step A: Find inorder successor
                // (smallest value in right subtree)
                TreeNode* temp = findMin(root->right);

                // Step B: Copy successor value to current node
                root->val = temp->val;

                // Step C: Delete the duplicate node from right subtree
                root->right = deleteNode(root->right, temp->val);
            }
        }

        // Return updated root after changes
        return root;
    }
};
