// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
//     answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
//     answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

// Note that the integers in the lists may be returned in any order.

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]

// Solution:
const findDifference = (nums1, nums2) => {
    let s1 = new Set(nums1)
    let s2 = new Set(nums2)
    let ans = [[], []];

    for (let i of s1) {
        if (!s2.has(i)) {
            ans[0].push(i)
        }
    }

    for (let i of s2) {
        if (!s1.has(i)) {
            ans[1].push(i)
        }
    }

    return ans;
};