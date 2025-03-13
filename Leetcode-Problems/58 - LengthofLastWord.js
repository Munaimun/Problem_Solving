// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.

// Input: s = "Hello World"1
// Output: 51
// Explanation: The last word is "World" with length 5.1

Solution:
const lengthOfLastWord = (s) => {
    let len = 0;
    let i = s.length - 1;

    // Skip any trailing spaces by moving the index `i` backwards
    while (i >= 0 && s[i] === " ") {
        i--;
    }

    // Count the length of the last word by moving `i` backwards
    // until a space or the beginning of the string is encountered
    while (i >= 0 && s[i] !== " ") {
        len++;
        i--;  // Move to the previous character
    }

    // Return the length of the last word
    return len;
};