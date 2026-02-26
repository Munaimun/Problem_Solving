#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    --------
    Given an array cost where cost[i] represents the cost of step i,
    you can climb either 1 or 2 steps at a time.

    You may start from step 0 or step 1.
    Return the minimum cost to reach the top (beyond last index).

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution
{
private:
    int INVALID = -1; // Represents uncomputed state
    vector<int> memo; // Memoization array

    /*
        Recursive function to compute minimum cost
        from current step to the top.
    */
    int findMinCost(int curStep, vector<int> &cost)
    {
        // Base Case:
        // If we go beyond the last stair,
        // no cost is needed.
        if (curStep >= cost.size())
            return 0;

        // If already computed, return stored result
        if (memo[curStep] != INVALID)
            return memo[curStep];

        // Option 1: Take 1 step
        int takeOneStep = findMinCost(curStep + 1, cost);

        // Option 2: Take 2 steps
        int takeTwoStep = findMinCost(curStep + 2, cost);

        // Store and return minimum cost
        return memo[curStep] = cost[curStep] + min(takeOneStep, takeTwoStep);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // Initialize memo array with INVALID
        memo.assign(cost.size(), INVALID);

        // We can start from step 0 or step 1
        return min(findMinCost(0, cost), findMinCost(1, cost));
    }
};