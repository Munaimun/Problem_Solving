// Time Complexity: O(n) where n is the length of the strings (since we loop through both s and t once)
// Space Complexity: O(1) as we use only a constant amount of extra space (just one char variable)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char res = 0; // Initialize result variable with 0 (acts as identity for XOR)

        // XOR all characters in string s
        for (char c : s)
            res ^= c;

        // XOR all characters in string t
        for (char c : t)
            res ^= c;

        // After all XOR operations, only the extra character will remain
        return res;
    }
};

int main()
{
    Solution sol;

    // Example input: t is s with an extra character 'e'
    cout << sol.findTheDifference("abcd", "abcde") << "\n"; // Output: e
}
