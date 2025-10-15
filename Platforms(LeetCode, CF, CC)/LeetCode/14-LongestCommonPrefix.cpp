// ✅ Time Complexity: O(N * M)
// N = number of strings in the vector
// M = length of the shortest string
// Because for each character in the first string, we compare with all others.

// ✅ Space Complexity: O(1) (excluding the output string)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";

        // Edge case: empty input
        if (strs.empty())
            return res;

        // Loop through characters of the first string
        for (int i = 0; i < strs[0].size(); i++)
        {
            // Compare this character with the same position in all other strings
            for (int j = 0; j < strs.size() - 1; j++)
            {
                // Check if index is out of range or characters differ
                if (i >= strs[j].size() || i >= strs[j + 1].size() || strs[j][i] != strs[j + 1][i])
                    return res;
            }

            // If all matched, add to result
            res += strs[0][i];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = sol.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
