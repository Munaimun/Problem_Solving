/**
 * Given the root of a binary tree, return the length of the diameter of the tree.
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 * The length of a path between two nodes is represented by the number of edges between them.
 * 
 * Time Complexity: O(N), where N is the number of nodes in the tree.
 * - Each node is visited once in a Depth-First Search (DFS).
 *
 * Space Complexity: O(H), where H is the height of the tree.
 * - In the worst case (skewed tree), the recursion stack can go up to O(N).
 * - In the best case (balanced tree), the recursion stack is O(log N).
 */
const diameterOfBinaryTree = (root) => {
    // Edge case: If the tree is empty, return diameter as 0.
    if (!root) return 0;

    let max = 0; // Variable to track the maximum diameter found.

    /**
     * Performs a Depth-First Search (DFS) to compute the height of each subtree.
     * Updates the maximum diameter encountered during traversal.
     */
    const dfs = (node) => {
        if (!node) return 0; // Base case: null nodes contribute 0 height.

        // Recursively find the height of the left and right subtrees.
        let left = dfs(node.left);
        let right = dfs(node.right);

        // Update max diameter: Sum of left and right subtree heights at this node.
        max = Math.max(left + right, max);

        // Return the height of the current node's subtree (1 + max child height).
        return Math.max(left, right) + 1;
    };

    dfs(root); // Start DFS from the root node.

    return max; // Return the maximum diameter found.
};
