/**
 * Solution for finding peak index in a mountain array
 * Problem: Given an array that increases to a peak then decreases,
 *          find the index of the peak element
 * Time Complexity: O(log n) - Binary search
 * Space Complexity: O(1) - Only using pointers
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;

        // Binary search to find peak
        while (left < right)
        {
            int mid = left + (right - left) / 2; // Avoid overflow

            // If mid element is less than next element,
            // we're on the ascending slope - peak is to the right
            if (arr[mid] < arr[mid + 1])
            {
                left = mid + 1; // Move left pointer right (search right half)
            }
            else
            {
                // We're on descending slope - peak is at mid or to the left
                right = mid; // Move right pointer left (search left half)
            }
        }

        // When loop ends, left == right at the peak index
        return left;
    }
};

int main()
{
    vector<int> arr = {1, 0, 10, 5, 2};
    Solution s;

    // Should output: 2 (index of peak element 10)
    cout << s.peakIndexInMountainArray(arr) << endl;

    return 0;
}