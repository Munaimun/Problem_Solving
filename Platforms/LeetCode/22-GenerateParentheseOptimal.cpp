// Time Complexity: O(4^n / √n)
//   - There are Catalan number Cn ≈ (1 / (n+1)) * (2n choose n) valid parentheses strings.
//   - This grows asymptotically as O(4^n / √n).
// Space Complexity: O(n)
//   - Recursion depth is at most 2n, so stack usage is O(n).
//   - The result vector stores all valid combinations (O(Cn)), 
//     but auxiliary space for recursion is O(n).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive backtracking function
    void solve(int n, string cur, int opening, int closing, vector<string> &ans)
    {
        // Base case: if the string has length 2*n, it's a valid parentheses combination
        if (cur.size() == n * 2)
        {
            ans.push_back(cur);
            return;
        }

        // Choice 1: Add an opening bracket if we still have some left
        if (opening < n)
            solve(n, cur + '(', opening + 1, closing, ans);

        // Choice 2: Add a closing bracket if it's valid (closing < opening)
        if (closing < opening)
            solve(n, cur + ')', opening, closing + 1, ans);
    }

    // Main function to generate parentheses
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string cur;
        solve(n, cur, 0, 0, ans); // start recursion with empty string
        return ans;
    }
};

int main()
{
    Solution s;

    // Example: n=1 → only one valid result "()"
    vector<string> res = s.generateParenthesis(1);

    for (auto i : res)
        cout << i << "\n";

    return 0;
}
