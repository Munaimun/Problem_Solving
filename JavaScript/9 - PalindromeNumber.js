// Given an integer x, return true if x is a palindrome and false otherwise.

// Example 1:
// Input: x = 121
// Output: true

// Solution:

const isPalindrome = (x) => {
    if (x < 0) return false;

    let rev = 0;
    let copy = x; // Copy the original number to compare later

    while (x > 0) {
        rev = (rev * 10) + (x % 10); // Get the last digit of x and add it to the reversed number
        x = Math.floor(x / 10); // Remove the last digit from x
    }

    // Compare the reversed number with the original number
    return rev === copy;
};