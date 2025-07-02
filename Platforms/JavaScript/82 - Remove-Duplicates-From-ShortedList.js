// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.


// Solution
const deleteDuplicates = (head) => {
    if (!head) return null;

    let dummy = new ListNode(-Infinity, head);
    let prev = dummy;
    let cur = head;

    while (cur) {
        let next = cur.next;

        // If cur has duplicates, skip all duplicates
        if (next && cur.val === next.val) {
            while (next && next.val === cur.val) {
                next = next.next;
            }
            prev.next = next; // Skip all duplicates
        } else {
            prev = cur; // Move prev forward only if no duplicates
        }
        cur = next; // Move cur forward
    }

    return dummy.next;
};

