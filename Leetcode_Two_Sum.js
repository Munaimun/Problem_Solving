function twoSum(nums, target) {
  const numIndices = {}; // Object to store number and its index

  for (let i = 0; i < nums.length; i++) {
    const complement = target - nums[i];

    // Check if the complement exists in the object
    if (complement in numIndices) {
      return [numIndices[complement], i]; // Return the indices
    }

    // Store the current number and its index in the object
    numIndices[nums[i]] = i;
  }
}

// Examples
console.log(twoSum([2, 7, 11, 15], 9)); // Output: [0, 1]
console.log(twoSum([3, 2, 4], 6)); // Output: [1, 2]
console.log(twoSum([3, 3], 6)); // Output: [0, 1]
