// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Solution:
const removeNthFromEnd = (head, n) => {
    let dummy = new ListNode(-1);
    dummy.next = head;

    let fast = dummy, slow = dummy;

    // Move fast n+1 steps ahead
    for (let i = 0; i <= n; i++) fast = fast.next;

    // Move fast to the end while moving slow
    while (fast) {
        fast = fast.next;
        slow = slow.next;
    }

    // Remove the nth node
    slow.next = slow.next.next;

    return dummy.next; // Return updated head
};
