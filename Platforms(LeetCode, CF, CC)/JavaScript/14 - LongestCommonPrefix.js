//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".
//
//Example 1:
//Input: strs = ["flower","flow","flight"]
//Output: "fl"

//Solution:
const longestCommonPrefix = (strs) => {
    // Edge case: If the input array is empty, return an empty string
    if (!strs.length) return "";

    // Edge case: If there's only one string, it is the common prefix
    if (strs.length === 1) return strs[0];

    // Initialize the prefix with the first string in the array
    let pre = strs[0];

    // Iterate through the array of strings starting from the second string
    for (let i = 1; i < strs.length; i++) {
        // Reduce the prefix until it matches the beginning of the current string
        while (strs[i].indexOf(pre) !== 0) {
            // Remove the last character from the prefix
            pre = pre.slice(0, pre.length - 1);

            // If the prefix becomes empty, no common prefix exists
            if (!pre) return "";
        }
    }

    // Return the longest common prefix found
    return pre;
};