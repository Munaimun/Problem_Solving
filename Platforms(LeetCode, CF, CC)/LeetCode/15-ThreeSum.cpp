/*
    Approach:
        - Sort the array to apply the two-pointer technique.
        - Fix one number (nums[i]), and use two pointers (j, k) to find the remaining two numbers.
        - Skip duplicates to avoid repeating triplets.

    Time Complexity: O(n^2)
        - Outer loop runs O(n), inner two-pointer scan takes O(n) in total for each i.
    Space Complexity: O(1) (excluding space for the result)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array to handle duplicates and use two pointers
        sort(nums.begin(), nums.end());

        // Iterate through each element and fix one number
        for (int i = 0; i < n; i++)
        {
            // Skip duplicate values for i to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1; // left pointer
            int k = n - 1; // right pointer

            // Step 3: Use two-pointer technique to find pairs that sum to -nums[i]
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                {
                    j++; // need a bigger number
                }
                else if (sum > 0)
                {
                    k--; // need a smaller number
                }
                else
                {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;

                    // Skip duplicates for j and k after a valid triplet
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Unique triplets that sum to zero:\n";
    for (auto triplet : result)
    {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
