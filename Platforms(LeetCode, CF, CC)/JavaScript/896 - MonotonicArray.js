// An array is monotonic if it is either monotone increasing or monotone decreasing.
// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.
// Example:
// Input: nums = [1,2,2,3]
// Output: true

// Solution: 
const isMonotonic = (nums) => {
    let increasing = true, decreasing = true;
    //if the array is empty
    if (nums.length === 0) {

    } else {
        for (let i = 0; i < nums.length - 1; i++) {
            if (nums[i] < nums[i + 1]) decreasing = false;

            if (nums[i] > nums[i + 1]) increasing = false
        }
    }

    return increasing || decreasing
}
