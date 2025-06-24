/**
 * Detects if a linked list contains a cycle using Floyd’s Cycle Detection Algorithm.
 * 
 * Approach:
 * - Uses two pointers: `slow` moves one step at a time, while `fast` moves two steps.
 * - If there is a cycle, `fast` will eventually meet `slow`, indicating a loop.
 * - If `fast` reaches the end (`null`), there is no cycle.
 * 
 * Time Complexity: O(N)
 * - In the worst case (when there is no cycle), `fast` traverses the entire list once, making it O(N).
 * - In the case of a cycle, `fast` moves at twice the speed of `slow`, meaning they meet within O(N) iterations.
 * 
 * Space Complexity: O(1)
 * - Uses only two pointers (`fast` and `slow`), so extra space usage is constant.
 * 
 */
const hasCycle = (head) => {
    // Two-pointer approach
    let fast = head;
    let slow = head;

    while (fast && fast.next) {
        fast = fast.next.next; // Move fast pointer two steps
        slow = slow.next; // Move slow pointer one step

        // If fast meets slow, cycle exists
        if (fast === slow) return true;
    }

    // No cycle detected
    return false;
};
