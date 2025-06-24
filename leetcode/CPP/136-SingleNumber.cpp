#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> f;

        for (int i = 0; i < nums.size(); i++)
        {
            f[nums[i]]++;
        }

        for (int j = 0; j < nums.size(); j++)
        {
            if (f[nums[j]] == 1)
                return nums[j];
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 2};
    cout << "Single number: " << sol.singleNumber(nums) << endl;
    return 0;
}
