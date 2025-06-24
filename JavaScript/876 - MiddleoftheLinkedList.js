// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]

// Solution: 
const middleNode = (head) => {
    let doubleMove = head;
    let half = head;

    while (doubleMove && doubleMove.next) {
        doubleMove = doubleMove.next.next;
        half = half.next
    }

    return half;
};