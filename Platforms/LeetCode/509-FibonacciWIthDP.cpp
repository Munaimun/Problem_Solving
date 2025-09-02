// Fibonacci using Dynamic Programming
//
// Time Complexity: O(n)
//   - Each number from 0..n is computed once and stored in memo.
//   - Subsequent calls are O(1) lookups.
// Space Complexity: O(n)
//   - Memoization array of size n+1.
//   - Recursion stack depth up to O(n).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function with memoization
    int solve(int n, vector<int> &memo) {
        // base cases
        if (n == 0 || n == 1) return n;

        // return cached result if already computed
        if (memo[n] != -1) return memo[n];

        // compute and store result
        memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
        return memo[n];
    }

    int fib(int n) {
        // create memoization array
        vector<int> memo(n + 1, -1);

        return solve(n, memo);
    }
};

int main() {
    Solution s;

    cout << s.fib(3) << endl;

    return 0;
}
