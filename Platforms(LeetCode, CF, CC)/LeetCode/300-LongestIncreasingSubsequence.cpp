/*
PROBLEM: Longest Increasing Subsequence (LIS) — Top Down DP (Memoization)

Given an integer array nums, return the length of the longest strictly increasing
subsequence. A subsequence keeps the original order but may skip elements.

Example:
nums = [10,9,2,5,3,7,101,18]
Answer = 4  → subsequence: [2,5,7,101]

APPROACH (Top-Down DP + Memoization):
- Define a recursive function findLis(i) = LIS length starting from index i
- From index i, try extending subsequence with every j > i where nums[j] > nums[i]
- Take the best extension: 1 + findLis(j)
- Store results in memo array so each index is computed only once

TIME COMPLEXITY:  O(n^2)
Each index explores future indices once due to memoization

SPACE COMPLEXITY: O(n)
Memo array + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> storeLis;   // memo table: storeLis[i] = LIS length starting at i
    int INVALID = -1;       // marker meaning "not computed yet"

    // Returns LIS length starting from given index
    int findLis(int index, vector<int>& nums) {

        // Base safety check (not strictly required here but safe guard)
        if (index >= nums.size())
            return 0;

        // Reference to memo slot — updates write directly into storeLis[index]
        int& currentLis = storeLis[index];

        // If already computed before → reuse cached answer (memoization hit)
        if (currentLis != INVALID)
            return currentLis;

        // At minimum, subsequence contains the element itself
        currentLis = 1;

        // Try extending subsequence with every later index
        for (int j = index + 1; j < nums.size(); j++) {

            // Only extend if strictly increasing
            if (nums[index] < nums[j]) {

                // Take current element + best subsequence from j
                currentLis = max(
                    currentLis,
                    1 + findLis(j, nums)
                );
            }
        }

        // Store + return computed LIS length for this index
        return currentLis;
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        // Initialize memo table with INVALID values
        storeLis.assign(nums.size(), INVALID);

        int maxLis = 0;

        // Try starting LIS from every index
        // Because the best subsequence can start anywhere
        for (int i = 0; i < nums.size(); i++) {

            maxLis = max(
                maxLis,
                findLis(i, nums)
            );
        }

        // Global best LIS length
        return maxLis;
    }
};


// ----- Demo main -----
int main() {
    vector<int> arr = {10,9,2,5,3,7,101,18};

    Solution s;
    cout << "LIS length = " << s.lengthOfLIS(arr) << "\n";

    return 0;
}

/*
LEARNING NOTES:

storeLis meaning after computation for sample input:
index : value : LIS-from-here
0 : 10 → 2
1 : 9  → 2
2 : 2  → 4   ← best start
3 : 5  → 3
4 : 3  → 3
5 : 7  → 2
6 : 101→ 1
7 : 18 → 1

Key insight:
We are computing "longest path starting from each index"
and memoizing results to avoid recomputation.
*/
