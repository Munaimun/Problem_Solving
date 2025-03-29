/**
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
 * 
 * Do not modify the linked list.
 *
 * Time Complexity: O(n) - The slow and fast pointers traverse the list at most twice.
 * Space Complexity: O(1) - Uses only two pointers (constant space).
 */
const detectCycle = (head) => {
    if (!head) return null; // Handle edge case: empty list.

    let slow = head;
    let fast = head;

    // Step 1: Detect if there is a cycle using two pointers.
    while (fast && fast.next) {
        slow = slow.next;       // Move slow by 1 step
        fast = fast.next.next;  // Move fast by 2 steps

        // If fast and slow meet, a cycle is detected.
        if (slow === fast) {
            break;
        }
    }

    // If no cycle was found, return null.
    if (!fast || !fast.next) {
        return null;
    }

    // Step 2: Find the entry point of the cycle.
    slow = head; // Reset slow to the head
    while (slow !== fast) {
        slow = slow.next;  // Move slow by 1 step
        fast = fast.next;  // Move fast by 1 step
    }

    return slow; // This is the node where the cycle begins.
};
