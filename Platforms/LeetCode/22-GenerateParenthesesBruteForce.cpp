// Problem: Generate all combinations of well-formed parentheses for n pairs
// Approach: Brute-force recursion generates all possible strings of length 2n
//           and then filters valid ones using a stack-based check (isValid).
// Time Complexity: O(n * 4^n)
//   - There are 2^(2n) = 4^n candidate strings
//   - Each string is checked in O(n) using isValid
// Space Complexity: O(n + C_n * n)
//   - O(n) recursion depth
//   - O(C_n * n) to store results (Catalan number C_n valid strings)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to check if a string of parentheses is valid
    bool isValid(string s)
    {
        stack<char> st;

        for (auto c : s)
        {
            if (c == '(')
            {
                st.push(c);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                    return false; // Found ')' without matching '('
            }
        }

        return st.empty(); // Valid if no unmatched '(' left
    }

    // Recursive function to generate all strings of length n
    void solve(string cur, int n, vector<string> &res)
    {
        if(cur.size() == n){
            if(isValid(cur)) res.push_back(cur); // Only keep valid ones
            return;
        }

        // Add '(' and recurse
        solve(cur+'(', n, res);

        // Add ')' and recurse
        solve(cur+')', n, res);
    }

    // Main function to generate parentheses
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string cur;
        solve(cur, 2*n, res); // Total length must be 2n
        return res;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);

    // Print results
    for(auto &s : ans) cout << s << "\n";

    return 0;
}
