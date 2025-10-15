/*
Time Complexity: O(n)
  - Each lookup and insert in the set takes O(log n) in worst case for `set`
Space Complexity: O(n)
  - Storing up to n elements in the set
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> s;

        bool flag = false;

        // Traverse the array
        for (int i = 0; i < n; i++)
        {
            // Check if current element already exists in the set
            if (s.find(nums[i]) != s.end())
            {
                // Duplicate found
                flag = true;
                break;
            }
            else
            {
                // Insert element into set if not already present
                s.insert(nums[i]);
            }
        }

        // Return true if duplicate found, else false
        return flag;
    }
};

int main()
{
    // Input array
    vector<int> nums = {1, 2, 3, 4};

    Solution sol;

    cout << sol.containsDuplicate(nums) << endl;

    return 0;
}
