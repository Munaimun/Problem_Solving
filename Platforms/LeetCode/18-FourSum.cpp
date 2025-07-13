/*
    Approach:
    - Sort the array to apply two-pointer technique.
    - Use two nested loops to fix the first two numbers.
    - For the remaining two numbers, use a two-pointer approach (left & right).
    - Skip duplicates at all levels to avoid repeated quadruplets.

    Time Complexity: O(n^3)
        - Two loops (a, b): O(n^2), inner while loop (c, d): O(n) total per outer pair
    Space Complexity: O(1) excluding result storage
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();

        // Sort array to handle duplicates and use two pointers
        sort(nums.begin(), nums.end());

        for (int a = 0; a < n; a++)
        {
            // Skip duplicate values for the first number
            if (a > 0 && nums[a] == nums[a - 1])
                continue;

            for (int b = a + 1; b < n; b++)
            {
                // duplicate values for the second number
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;

                int c = b + 1; // left pointer
                int d = n - 1; // right pointer

                // Step 2: Two-pointer search for remaining two numbers
                while (c < d)
                {
                    // Use long long to prevent integer overflow
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];

                    if (sum < target)
                    {
                        c++; // need a bigger sum
                    }
                    else if (sum > target)
                    {
                        d--; // need a smaller sum
                    }
                    else
                    {
                        // Found a valid quadruplet
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++, d--;

                        // Skip duplicates for third and fourth numbers
                        while (c < d && nums[c] == nums[c - 1])
                            c++;
                        while (c < d && nums[d] == nums[d + 1])
                            d--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Unique quadruplets that sum to " << target << ":\n";
    for (auto &quad : result)
    {
        for (int num : quad)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
