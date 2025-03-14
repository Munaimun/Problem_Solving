/**
 * Determines whether two binary trees are identical in structure and values.
 * 
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 * 
 * Time Complexity: O(N) - Each node is visited once.
 * Space Complexity: O(H) - Due to recursive call stack, where H is the height of the tree.
 */
const isSameTree = (p, q) => {
    // Base Case: If both nodes are null, they are identical
    if (!p && !q) return true;

    // If one of the nodes is null or values do not match, trees are not identical
    if (!p || !q || p.val !== q.val) return false;

    // Recursively check left and right subtrees
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
};
