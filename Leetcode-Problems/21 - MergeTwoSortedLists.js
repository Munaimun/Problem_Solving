// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Solution:
const mergeTwoLists = (list1, list2) => {
    let dummy = new ListNode(-1); // using dummy node
    let pre = dummy;

    while (list1 && list2) {
        if (list1.val <= list2.val) {
            pre.next = list1;
            list1 = list1.next
        } else {
            pre.next = list2;
            list2 = list2.next
        }
        pre = pre.next
    }

    // Attaching the remaining part of the non-empty list
    pre.next = list1 || list2;

    return dummy.next;
};