/*
    Approach: Floyd's Tortoise and Hare (Cycle Detection)

    Time Complexity: O(n)
        - In the worst case, both pointers traverse the array linearly.

    Space Complexity: O(1)
        - No extra space is used; all operations are done in-place.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0], fast = nums[0];

        // Move slow by 1 step and fast by 2 steps to detect cycle
        do
        {
            slow = nums[slow];       // 1 step
            fast = nums[nums[fast]]; // 2 steps
        } while (slow != fast); // Repeat until they meet (inside the cycle)

        // Reset slow to start to find entrance to cycle (duplicate number)
        slow = nums[0];

        // Move both one step at a time; the meeting point is the duplicate
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // or fast, both are now at the duplicate number
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2}; // Example input
    cout << "Duplicate number: " << sol.findDuplicate(nums) << endl;

    return 0;
}
