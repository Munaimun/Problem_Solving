// Time Complexity: O(n), where n is the size of the input vector nums
// Space Complexity: O(1), as the running sum is computed in-place without extra space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Computes the running sum of the input vector nums in-place
    // After processing, nums[i] contains the sum of elements from nums[0] to nums[i]
    vector<int> runningSum(vector<int> &nums)
    {
        // Start from second element and add the previous element's value to current element
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {1, 2, 3, 4};

    vector<int> result = sol.runningSum(v);

    for (int val : result)
        cout << val << " ";
    cout << "\n";

    return 0;
}
