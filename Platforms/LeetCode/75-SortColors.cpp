/**
 * Dutch National Flag Algorithm to sort an array of 0s, 1s, and 2s.
 *
 * Time Complexity: O(n)
 *   - The array is traversed once with three pointers (mid, low, high).
 *   - Each element is visited at most once.
 *
 * Space Complexity: O(1)
 *   - In-place sorting; no extra data structures are used.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;                // Boundary for 0s
        int mid = 0;                // Current index
        int high = nums.size() - 1; // Boundary for 2s

        // Traverse the array while mid does not cross high
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                // Swap current element with low and move both pointers forward
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                // 1 is in correct position, move mid pointer
                mid++;
            }
            else // nums[mid] == 2
            {
                // Swap current element with high and move high pointer backward
                swap(nums[mid], nums[high]);
                high--;
                // Do not increment mid here, because swapped element may be 0 or 1
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sol.sortColors(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
