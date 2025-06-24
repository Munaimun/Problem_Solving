// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Solution:
const searchInsert = (nums, target) => {
    let l = 0;
    let r = nums.length - 1;

    while (l <= r) {
        let mid = Math.floor((l + r) / 2);

        if (nums[mid] === target) {
            return mid;
            // If the middle element is greater than the target,
            // the target must be in the left half, so move `r` to mid - 1
        } else if (nums[mid] > target) {
            r = mid - 1;

            // Otherwise, the target must be in the right half,
            // so move `l` to mid + 1
        } else {
            l = mid + 1;
        }
    }

    return l;
};