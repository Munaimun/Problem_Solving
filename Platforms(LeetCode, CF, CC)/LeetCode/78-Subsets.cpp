/**
 * Problem: Generate all subsets (the power set) of a given vector of unique integers.
 *
 * Approach: Backtracking
 * - At each index `i`, we have two choices:
 *   1) Include nums[i] in the current subset
 *   2) Exclude nums[i] and move forward
 * - When we reach i == nums.size(), we push the current subset into the result.
 *
 * Time Complexity: O(2^n * n)
 *   - There are 2^n possible subsets for n elements.
 *   - Copying the current subset into the result takes O(n) in the worst case.
 *
 * Space Complexity: O(n)
 *   - Recursion stack can go up to depth n.
 *   - Current subset (`cur`) can hold up to n elements.
 *   - Output (`res`) itself takes O(2^n * n) space.
 */

// doc
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(const vector<int> &nums, vector<int> &cur, vector<vector<int>> &res, int i)
    {
        // Base case: If we have considered all elements, save the current subset
        if (i == nums.size())
        {
            res.push_back(cur); // Push a copy of current subset
            return;
        }

        // --- Choice 1: Include nums[i] ---
        cur.push_back(nums[i]);
        backtrack(nums, cur, res, i + 1);

        // Backtrack: remove last element to explore the exclude path
        cur.pop_back();

        // --- Choice 2: Exclude nums[i] ---
        backtrack(nums, cur, res, i + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res; // Stores all subsets
        vector<int> cur;         // Current subset being built
        backtrack(nums, cur, res, 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = s.subsets(nums);

    // Print all subsets
    for (auto &subset : ans)
    {
        cout << "[ ";
        for (auto val : subset)
            cout << val << " ";
        cout << "]" << endl;
    }

    return 0;
}
