// Time Complexity: O(2^n) 
// - Each element has two choices: either included or excluded → 2^n subsets.
// - Sorting takes O(n log n), but O(2^n) dominates.
// Space Complexity: O(n) (ignoring result storage)
// - Recursion depth is at most n (stack frames).
// - The result itself stores O(2^n) subsets, but auxiliary space is O(n).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void allSubSets(vector<int>& nums, vector<int>& cur, vector<vector<int>> &res, int i) {
        // base case
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }

        // Include nums[i]
        cur.push_back(nums[i]);
        allSubSets(nums, cur, res, i + 1);
        cur.pop_back();

        // Skip duplicates
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

        // Exclude nums[i] and move forward
        allSubSets(nums, cur, res, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates

        vector<vector<int>> res;
        vector<int> cur;

        allSubSets(nums, cur, res, 0);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution s;
    vector<vector<int>> ans = s.subsetsWithDup(nums);

    for (auto &subset : ans) {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "] ";
    }

    return 0;
}
