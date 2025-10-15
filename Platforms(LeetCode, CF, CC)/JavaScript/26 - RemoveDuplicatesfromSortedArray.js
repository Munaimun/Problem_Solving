// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]

// Solution:

const removeDuplicates = (nums) => {
    // Edge case: Empty array
    if (nums.length === 0) return 0;

    let i = 1; // in sorted array the first element is unique

    for (let j = 1; j < nums.length; j++) {
        if (nums[j] !== nums[i - 1]) { // If current element is different from previous unique element
            nums[i] = nums[j]; // Place the unique element at index i
            i++; // Move pointer forward
        }
    }

    return i; // i represents the number of unique elements
};