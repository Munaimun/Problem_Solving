// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

// Solution
const deleteDuplicates = (head) => {
    if (!head) return null;

    let dummy = new ListNode(-Infinity, head); // Dummy node to handle edge cases
    let prev = dummy;
    let cur = head;

    while (cur) {
        // Check if current node has duplicates
        if (cur.next && cur.val === cur.next.val) {
            // Skip all nodes with the same value
            while (cur.next && cur.val === cur.next.val) {
                cur = cur.next;
            }
            // Link prev to the node after the duplicates
            prev.next = cur.next;
        } else {
            // No duplicates, move prev pointer
            prev = cur;
        }
        // Move cur pointer
        cur = cur.next;
    }

    return dummy.next;
};
