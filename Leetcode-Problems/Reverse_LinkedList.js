// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

var reverseList = function (head) {
  let currentNode = head;
  let prevNodePtr = null;
  let nextPtr;

  while (currentNode !== null) {
    nextPtr = currentNode.next;
    currentNode.next = prevNodePtr;
    prevNodePtr = currentNode;
    currentNode = nextPtr;
  }
  return prevNodePtr;
};

console.log(reverseList(head));
