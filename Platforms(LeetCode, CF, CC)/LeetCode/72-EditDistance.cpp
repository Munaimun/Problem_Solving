// Problem Statement:
// Given two strings word1 and word2, find the minimum number of operations
// required to convert word1 into word2. Allowed operations are:
// 1. Insert a character
// 2. Delete a character
// 3. Replace a character

// Approach:
// We use **Top-Down Dynamic Programming (Recursion + Memoization)**.
// Each state dp[i][j] represents the minimum number of operations required
// to convert the substring word1[i...] to word2[j...].

// Time Complexity: O(n * m) where n = word1.size(), m = word2.size()
// Space Complexity: O(n * m) for the memoization table
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int INVALID = -1;

    int w1Len, w2Len;                  // lengths of word1 and word2
    string w1, w2;                      // class copies of the strings
    vector<vector<int>> storeMinDist;   // DP table (memoization)

    // Recursive function to compute minimum edit distance
    int findMinDist(int w1Idx, int w2Idx) {
        // Base case 1: word1 finished, insert remaining characters of word2
        if (w1Idx == w1Len)
            return w2Len - w2Idx;

        // Base case 2: word2 finished, delete remaining characters of word1
        if (w2Idx == w2Len)
            return w1Len - w1Idx;

        // Reference to DP table cell to store/reuse result
        int& minDist = storeMinDist[w1Idx][w2Idx];

        // If already computed, return stored value
        if (minDist != INVALID)
            return minDist;

        // If characters match, move both indices forward
        if (w1[w1Idx] == w2[w2Idx])
            return minDist = findMinDist(w1Idx + 1, w2Idx + 1);

        // Otherwise, try all three operations:
        int insert  = 1 + findMinDist(w1Idx, w2Idx + 1);     // insert word2[j] into word1
        int dlt     = 1 + findMinDist(w1Idx + 1, w2Idx);     // delete word1[i]
        int replace = 1 + findMinDist(w1Idx + 1, w2Idx + 1); // replace word1[i] with word2[j]

        // Store the minimum cost in DP table and return
        return minDist = min({insert, dlt, replace});
    }

public:
    int minDistance(string word1, string word2) {
        w1 = word1;
        w2 = word2;
        w1Len = w1.size();
        w2Len = w2.size();

        // Initialize DP table with INVALID (-1)
        storeMinDist.assign(w1Len + 1, vector<int>(w2Len + 1, INVALID));

        // Start recursion from beginning of both strings
        return findMinDist(0, 0);
    }
};