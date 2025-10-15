#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            int first = nums[i];
            int sec = target - first;

            if (m.find(sec) != m.end())
            {
                return {i, m[sec]};
            }

            m[first] = i;
        }

        return {}; // if no solution is found
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}
