// ======================================================
// Problem: Longest Common Subsequence (LCS)
//
// Given two strings text1 and text2, return the length
// of their longest common subsequence.
//
// A subsequence is a sequence that appears in the same
// relative order, but not necessarily contiguous.
//
// Example:
// text1 = "abcde", text2 = "ace"
// LCS = "ace" → length = 3
// ======================================================
//
// Time Complexity:
//   O(n * m)
//   - n = length of text1
//   - m = length of text2
//   Each (i, j) state is solved once using memoization.
//
// Space Complexity:
//   O(n * m) for memo table
//   + O(n + m) recursion stack (worst case)
//
// ======================================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // memo[i][j] will store:
    // LCS length for text1[i ... end] and text2[j ... end]
    vector<vector<int>> memo;

    // We use -1 to mean:
    // "This state has NOT been computed yet"
    int INVALID = -1;

private:
    int solve(int i, int j, string& text1, string& text2) {

        // Base case:
        // If either string is exhausted,
        // no common subsequence is possible.
        if (i == text1.size() || j == text2.size())
            return 0;

        // If already computed, reuse it
        // (this is where DP saves time)
        if (memo[i][j] != INVALID)
            return memo[i][j];

        // Case 1: characters match
        if (text1[i] == text2[j]) {
            // We take this character
            // and move both pointers forward
            memo[i][j] = 1 + solve(i + 1, j + 1, text1, text2);
        }
        // Case 2: characters do NOT match
        else {
            // Two choices:
            // 1) Skip character from text1
            // 2) Skip character from text2
            // Take the better option
            memo[i][j] = max(
                solve(i + 1, j, text1, text2),
                solve(i, j + 1, text1, text2)
            );
        }

        // Store result before returning
        return memo[i][j];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {

        // Edge case:
        // If any string is empty, LCS = 0
        if (text1.empty() || text2.empty())
            return 0;

        // Create memo table:
        // rows = text1 length
        // cols = text2 length
        // initialize all cells with -1
        memo.assign(
            text1.size(),
            vector<int>(text2.size(), INVALID)
        );

        // Start recursion from index (0, 0)
        return solve(0, 0, text1, text2);
    }
};
