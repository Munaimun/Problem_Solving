// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// Input: s = "abc", t = "ahbgdc"
// Output: true

// Solution:
const isSubsequence = (s, t) => {
    let i = 0, j = 0;

    while (i < s.length && j < t.length) {
        if (s[i] === t[j]) { // If characters match, move both pointers forward
            i++;
            j++
        } else {
            j++ // If they don't match, only move `j` to check the next character in `t`
        }
    }
    // If `i` reached the end of `s`, it means all characters of `s` appeared in order in `t` and it will return true
    return i === s.length;
};