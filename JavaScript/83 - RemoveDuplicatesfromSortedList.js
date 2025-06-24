// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Input: head = [1,1,2]
// Output: [1,2]

// Solution:
const deleteDuplicates = (head) => {
    if (!head) return null;

    let cur = head;

    while (cur && cur.next) {
        // if the current value and the next value to it is same
        while (cur.next && cur.val === cur.next.val) {
            cur.next = cur.next.next // move forward until the value is not same
        }
        cur = cur.next
    }

    return head;
};