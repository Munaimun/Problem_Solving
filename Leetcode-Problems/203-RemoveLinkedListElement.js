// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// Solution:

const removeElements = (head, val) => {

    // If the first few nodes in the list have val equal to the target value, the head will be updated to point to the first node that doesn't match val
    while (head !== null && head.val === val) {
        head = head.next;
    }


    let cur = head;
    let pre = null;

    while (cur !== null) {
        if (cur.val === val) { // if cur node is equal to the val to remove
            pre.next = cur.next // Then pre will point to cur.next, skipping the immediate node after it
        } else {
            pre = cur // if the cur node is not equal to the val, the pre will will update to the cur node
        }
        cur = cur.next
    }
    return head;
}