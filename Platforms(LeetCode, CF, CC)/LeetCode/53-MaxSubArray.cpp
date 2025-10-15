#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm implementation to find the maximum sum of a contiguous subarray
class Solution
{
public:
    // Function to calculate the maximum subarray sum
    int maxSubArray(vector<int> &nums)
    {
        // Initialize current subarray sum and the maximum sum found so far
        int curSum = 0;
        int maxSum = INT_MIN;

        // Iterate through the array to apply Kadane's Algorithm
        for (int i : nums)
        {
            curSum += i;                  // Extend the current subarray with the current element
            maxSum = max(curSum, maxSum); // Update maxSum if the current subarray sum is greater

            if (curSum < 0) // If current subarray sum becomes negative,
                curSum = 0; // reset it to 0 to start a new subarray
        }

        return maxSum; // Return the maximum subarray sum found
    }
};

int main()
{
    Solution sol;

    // Example input: mix of positive and negative numbers
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Output: the maximum sum of a contiguous subarray
    cout << sol.maxSubArray(vec) << "\n";

    return 0;
}
