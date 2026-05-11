/*
    Problem Statement:
    ------------------
    Given a sorted array of distinct integers and a target value,
    return the index if the target is found.

    If the target is not found, return the index where it would be
    inserted in order while maintaining the sorted order.

    Example:
    --------
    nums = [1,3,5,6], target = 5  -> Output: 2
    nums = [1,3,5,6], target = 2  -> Output: 1
    nums = [1,3,5,6], target = 7  -> Output: 4

    Time Complexity:
    ----------------
    O(log n)
    Because we divide the search space in half every iteration.

    Space Complexity:
    -----------------
    O(1)
    No extra space is used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Left pointer starts from beginning
        int l = 0;

        // Right pointer starts from end
        int r = nums.size() - 1;

        // Continue searching while search space is valid
        while (l <= r) {

            // Find middle index
            int mid = (l + r) / 2;

            // If target is found, return its index
            if (nums[mid] == target) {
                return mid;
            }

            // If middle value is greater than target,
            // move to the left half
            else if (nums[mid] > target) {
                r = mid - 1;
            }

            // Otherwise search in the right half
            else {
                l = mid + 1;
            }
        }

        /*
            If target is not found,
            'l' becomes the correct insertion position.
        */
        return l;
    }
};


/*
    Example Walkthrough:
    --------------------
    nums = [1,3,5,6]
    target = 2

    Iteration 1:
    ------------
    l = 0, r = 3
    mid = 1
    nums[mid] = 3

    3 > 2
    => move left
    r = mid - 1 = 0

    Iteration 2:
    ------------
    l = 0, r = 0
    mid = 0
    nums[mid] = 1

    1 < 2
    => move right
    l = mid + 1 = 1

    Loop ends:
    -----------
    l = 1, r = 0

    Return l = 1

    Final array would become:
    [1,2,3,5,6]
*/