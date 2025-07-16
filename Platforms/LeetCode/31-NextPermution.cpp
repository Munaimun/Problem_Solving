/*
    Time Complexity: O(n)
    - One pass to find the pivot
    - One pass to find the next greater element
    - One reverse (which is O(n))
    So overall: O(n)

    Space Complexity: O(1)
    - We modify the input array in-place with constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int pivot = -1;

        // Step 1: Find the first index from the right where nums[i] < nums[i + 1]
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break; // break as we want the *first* such occurrence from the end
            }
        }

        // Step 2: If no such index found, reverse the entire array (last permutation case)
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: From the end, find the first element greater than nums[pivot] and swap
        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix starting right after pivot
        int left = pivot + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};

int main()
{
    // Example usage:
    vector<int> nums = {1, 2, 3};
    Solution().nextPermutation(nums);
    for (int num : nums)
        cout << num << " "; // Output: 1 3 2

    return 0;
}
