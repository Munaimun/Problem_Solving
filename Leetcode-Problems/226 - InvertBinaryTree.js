/**
 * Inverts a binary tree by swapping the left and right subtrees of each node.
 * 
 * Time Complexity: O(n) - Each node is visited once.
 * Space Complexity: O(h) - Recursive call stack, where h is the height of the tree.
 *
 */

const invertTree = (root) => {
    if (root === null) return null; // Base case: If tree is empty, return null

    // Swap left and right child nodes
    const temp = root.left;
    root.left = root.right;
    root.right = temp;

    // Recursively invert left and right subtrees
    invertTree(root.left);
    invertTree(root.right);

    return root;
};