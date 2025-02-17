// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// Input: head = [1,2,2,1]
// Output: true

// Solution using two pointer method:

// helper function for reversing
const reverse = head => {
    let cur = head;
    let prev = null;
    let next;

    while (cur) {
        next = cur.next;
        cur.next = prev;
        prev = cur
        cur = next
    }
    return prev
}

// main function
const isPalindrome = (head) => {
    let fast = head;
    let slow = head;
    let startPtr = head;
    let len = 0;

    // Move fast pointer twice as fast as slow pointer to find the middle
    while (fast && fast.next) {
        fast = fast.next.next;
        slow = slow.next;
        len++
    }

    // Reverse the second half of the list
    let mid = reverse(slow)

    // Compare first half with the reversed second half
    while (len) {
        len--;
        if (mid.val !== startPtr.val) return false; // Mismatch found, not a palindrome
        // otherwise keep going
        mid = mid.next
        startPtr = startPtr.next
    }

    return true
};