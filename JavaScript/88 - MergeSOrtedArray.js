// 88 - MergeSOrtedArray

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n

// Example:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6]

// Solution:
const merge = (nums1, m, nums2, n) => {
    let firstPointer = m - 1; // Pointer for nums1
    let secondPointer = n - 1; // Pointer for nums2
    let i = m + n - 1; //<--Or nums1.length -1 (Pointer for the last position in nums1)

    while (secondPointer >= 0) { // Process nums2 elements
        let firstVal = firstPointer >= 0 ? nums1[firstPointer] : -Infinity; //-Infinity ensures that the remaining elements in nums2 are always considered "larger"
        let secondVal = nums2[secondPointer];

        if (firstVal > secondVal) {
            nums1[i] = firstVal;
            firstPointer--; // Move nums1 pointer
        } else {
            nums1[i] = secondVal;
            secondPointer--; // Move nums2 pointer
        }
        i--; // Move the pointer for the merged array
    }
};
