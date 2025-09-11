/*
Time Complexity: O(n * n!) 
    - There are n! permutations for n elements.
    - Copying each permutation to the result takes O(n) time.
Space Complexity: O(n * n!) including output
    - Auxiliary space: O(n) for recursion stack + cur + used
    - Result array stores n! permutations of size n → O(n * n!)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void permutation(vector<int> &nums, vector<int> &cur, vector<vector<int>> &res, vector<bool> &used)
    {
        // Base case: if current permutation has same size as input array
        if (cur.size() == nums.size())
        {
            res.push_back(cur); // store a copy of current permutation in result
            return;             // return to previous recursion call
        }

        // Loop through all elements in nums
        for (int i = 0; i < nums.size(); i++)
        {
            // Only consider elements that are not used in current permutation
            if (!used[i])
            {
                // Choose element nums[i]
                used[i] = true;          // mark it as used
                cur.push_back(nums[i]);  // add it to current permutation

                // Recurse to build permutations with next elements
                permutation(nums, cur, res, used);

                // Backtracking step: undo the choice
                cur.pop_back();    // remove last element to try next option
                used[i] = false;   // mark it as unused for future iterations
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;      // stores all permutations
        vector<int> cur;              // stores current permutation during recursion
        vector<bool> used(nums.size(), false); // tracks which elements are used

        // Start recursion with empty current permutation
        permutation(nums, cur, res, used);

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = s.permute(nums);
    for (auto &v : ans) {
        for (auto x : v) cout << x << " ";
        cout << endl;
    }

    return 0; // Program ends
}
