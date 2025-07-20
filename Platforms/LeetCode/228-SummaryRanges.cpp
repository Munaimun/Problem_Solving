/*
Time Complexity: O(n)
  - We make a single pass through the input array once.

Space Complexity: O(k)
  - Where k is the number of ranges in the output.
  - The output array of strings uses extra space proportional to the number of ranges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res; // To store the final ranges

        int n = nums.size();
        if (n == 0)
            return res; // Handle empty input to avoid errors

        int start = nums[0]; // Start of the current range

        // Loop through nums from index 1 to n (one past last index)
        for (int i = 1; i <= n; i++)
        {
            // Condition to check if we reached the end or found a break in consecutive numbers
            if (i == n || nums[i] != nums[i - 1] + 1)
            {
                // If start equals the last number in the current range,
                // it means the range has only one number
                if (start == nums[i - 1])
                {
                    res.push_back(to_string(start)); // Add single number as string
                }
                else
                {
                    // Otherwise, add the full range "start->end"
                    res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }

                // If not at the end, update start to the new range start
                if (i < n)
                    start = nums[i];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {0, 1, 2, 4, 5, 7};

    vector<string> ranges = sol.summaryRanges(nums);

    for (const string &range : ranges)
    {
        cout << range << endl;
    }

    return 0;
}
