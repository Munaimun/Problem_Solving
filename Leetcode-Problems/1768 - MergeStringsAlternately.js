// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.

// Example 1:
// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"

//solution
var mergeAlternately = function (word1, word2) {
  let mergedStr = "";
  const maxLen = Math.max(word1.length, word2.length);

  for (let i = 0; i < maxLen; i++) {
    // If there is a character at the current index in word1 and word2, add it to mergedStr
    if (word1[i]) mergedStr += word1[i];
    if (word2[i]) mergedStr += word2[i];
  }
  return mergedStr;
};
