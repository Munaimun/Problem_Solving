// Problem: Given the root of a binary tree, return the level order traversal 
// of its nodes' values (i.e., from left to right, level by level).
// Example:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Time Complexity: O(n), where n is the number of nodes in the tree.
// Each node is visited exactly once.
// Space Complexity: O(n), due to the queue storing nodes at each level.

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;       // Stores final level-order traversal
        
        if (root == NULL)              // Edge case: empty tree
            return ans;

        queue<TreeNode*> q;            // Queue to perform BFS
        q.push(root);                  // Start BFS from root

        while (!q.empty()) {
            int s = q.size();          // Number of nodes at current level
            vector<int> v;             // Store values of current level

            for (int i = 0; i < s; i++) {
                TreeNode* curNode = q.front();  // Get front node from queue
                q.pop();                        // Remove it from queue

                // Add children to queue if they exist
                if (curNode->left != NULL)
                    q.push(curNode->left);
                if (curNode->right != NULL)
                    q.push(curNode->right);

                v.push_back(curNode->val);      // Add current node value to level
            }

            ans.push_back(v);         // Add current level values to answer
        }

        return ans;                  // Return final level-order traversal
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result
    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
