// Time Complexity: O(n) — single pass through the array to compute the sum
// Space Complexity: O(1) — only a few integer variables used, no extra data structures

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // Get the size of the array (which is n, since one number from 0 to n is missing)
        int n = nums.size();

        // Calculate the expected sum of numbers from 0 to n
        int sum = n * (n + 1) / 2;

        // Calculate the actual sum of elements in the array
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }

        // The difference between expected and actual sum gives the missing number
        int res = sum - total;
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 0, 1};
    cout << sol.missingNumber(nums);

    return 0;
}
