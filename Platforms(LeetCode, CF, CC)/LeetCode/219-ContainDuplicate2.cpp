/*
 * Time Complexity: O(n)
 *   - We traverse the array once.
 *   - Each insertion, lookup, and deletion in unordered_set is O(1) on average.
 * Space Complexity: O(min(n, k))
 *   - The unordered_set stores at most k elements at any time.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window; // sliding window to store up to k elements
        int n = nums.size();

        bool flag = false; // flag to track if duplicate found within distance k
        for (int i = 0; i < n; i++)
        {
            // Check if current element already exists in the window (duplicate within range)
            if (window.find(nums[i]) != window.end())
            {
                flag = true; // duplicate found
                break;       // no need to check further, exit loop
            }

            // Insert current element into the window
            window.insert(nums[i]);

            // If window size exceeds k, remove the oldest element to maintain size k
            if (window.size() > k)
            {
                window.erase(nums[i - k]);
            }
        }

        // Return true if duplicate found within k distance, else false
        return flag;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout << sol.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}
