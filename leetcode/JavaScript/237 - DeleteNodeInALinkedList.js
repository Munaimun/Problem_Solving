// There is a singly-linked list head and we want to delete a node node in it.
// You are given the node to be deleted node. You will not be given access to the first node of head.
// Do not return anything, modify node in-place instead.

// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]

// Solution:
const deleteNode = (node) => {
    let next = node.next.next;
    node.val = node.next.val;
    node.next = next
};