// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

// Example:
// Input: nums = [1,3,4,2,2]
// Output: 2

const firstRecurrinChar = (nums) => {
  let map = {};
  for (let i = 0; i < nums.length; i++) {
    if (map[nums[i]] !== undefined) {
      return nums[i];
    } else {
      map[nums[i]] = i;
    }
  }
  return undefined;
};

console.log(firstRecurrinChar([1, 3, 4, 2, 2]));
