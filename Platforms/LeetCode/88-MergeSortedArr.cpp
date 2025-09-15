// Time Complexity: O(m + n)
// Main loop:** At most m + n iterations (each iteration processes one element)
// Cleanup loops:** Process remaining elements (total remaining ≤ m + n)
// Copy operation:** O(m + n) to assign `ans` to `nums1`
// Total:** O(m + n) + O(m + n) = O(m + n)

// Space Complexity: O(m + n)
// Auxiliary array `ans`:** O(m + n) space
// Variables (i, j, k):** O(1) space
// Total:** O(m + n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int k = 0, i = 0, j = 0;
        vector<int> ans(m + n, 0);

        // Main merge loop - compare elements from both arrays
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
                ans[k++] = nums1[i++];
            else
                ans[k++] = nums2[j++];
        }

        // Add remaining elements from nums1 (if any)
        while (i < m)
            ans[k++] = nums1[i++];

        // Add remaining elements from nums2 (if any)
        while (j < n)
            ans[k++] = nums2[j++];

        // Copy merged result back to nums1
        nums1 = ans;
    }
};

int main()
{
    Solution solve;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    solve.merge(nums1, m, nums2, n);

    // Print result
    for (int x : nums1)
        cout << x << " ";

    return 0;
}

// ### Example Trace:
// Initial: nums1 = [1,2,3,0,0,0], nums2 = [2,5,6], m=3, n=3
// ans = [0,0,0,0,0,0]

// Step 1: Compare 1 vs 2 → take 1 → ans = [1,0,0,0,0,0]
// Step 2: Compare 2 vs 2 → take 2 → ans = [1,2,0,0,0,0]
// Step 3: Compare 3 vs 2 → take 2 → ans = [1,2,2,0,0,0]
// Step 4: Compare 3 vs 5 → take 3 → ans = [1,2,2,3,0,0]
// Step 5: nums1 exhausted, copy remaining from nums2
//         → ans = [1,2,2,3,5,6]

// Final: nums1 = [1,2,2,3,5,6]