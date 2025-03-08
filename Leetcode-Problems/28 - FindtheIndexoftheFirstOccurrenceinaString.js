// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Solution:
const strStr = (haystack, needle) => {
    // If the length of haystack is smaller than needle, needle can't be found
    if (haystack.length < needle.length) return -1;

    // If haystack and needle are the same, or needle is an empty string, return 0
    if (haystack === needle || needle.length === 0) return 0;

    for (let i = 0; i < haystack.length; i++) {
        // Check if the current character in haystack matches the first character of needle
        if (haystack[i] === needle[0]) {
            // Extract a substring from haystack starting at index i with a length of needle
            let sub = haystack.substring(i, needle.length);

            // Compare the extracted substring with needle
            if (sub === needle) {
                return i; // Return the starting index of the first occurrence
            }
        }
    }

    // If needle is not found in haystack, return -1
    return -1;
};


// Solution using builtin function:
const StrStr = (haystack, needle) => {
    if (haystack.length < needle.length) return -1;

    return haystack.indexOf(needle)
};