// Problem: 
// Given a sorted array of integers `nums` and an integer `target`,
// return the index of `target` if it exists in the array.
// Otherwise, return -1.
//
// Approach:
// Use Binary Search to efficiently reduce the search space by half each time.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Initialize search boundaries
        int low = 0, high = n - 1;

        // Continue searching while the range is valid
        while (low <= high) {
            // Calculate mid safely to avoid overflow
            int mid = low + (high - low) / 2;

            // Case 1: Found the target
            if (nums[mid] == target) {
                return mid;
            }

            // Case 2: Target is in the right half
            else if (nums[mid] < target) {
                low = mid + 1;
            }

            // Case 3: Target is in the left half
            else {
                high = mid - 1;
            }
        }

        // Target not found
        return -1;
    }
};