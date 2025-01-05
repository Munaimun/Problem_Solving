// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Solution:
const moveZeroes = (nums) => {
    // Pointer to track the position where the next non-zero element should go
    let lastZeroIdx = 0;

    // First loop: Iterate through the array to move non-zero elements forward
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            // Place the non-zero element at the position indicated by lastZeroIdx
            nums[lastZeroIdx] = nums[i];
            lastZeroIdx++;
        }
    }

    // Second loop: Fill the remaining positions in the array with zeroes
    for (let i = lastZeroIdx; i < nums.length; i++) {
        nums[i] = 0; // Replace the leftover elements with zeroes
    }
};

