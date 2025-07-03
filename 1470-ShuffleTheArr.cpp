// Time Complexity: O(n), where n is the number of pairs (input size is 2n, loop runs n times)
// Space Complexity: O(n), since we create a new array of size 2n for the result

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            res.push_back(nums[i]);     // Push x_i from the first half
            res.push_back(nums[n + i]); // Push y_i from the second half
        }

        return res; // Return the interleaved result
    }
};

int main()
{
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    Solution sol;

    vector<int> res = sol.shuffle(nums, n);

    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
