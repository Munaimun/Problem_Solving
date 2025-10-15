/*
    Problem: Remove all occurrences of a substring `part` from string `s`.

    Approach:
    - Use a loop to repeatedly search for the substring `part` inside `s`.
    - If found, remove it using `erase()`.
    - Continue until no more occurrences are found.

    Time Complexity:
    - O(N * M), where N = length of `s`, M = length of `part`
      - `find(part)` is O(N), and can happen up to O(N/M) times in the worst case.

    Space Complexity:
    - O(1) auxiliary space (in-place modifications on string `s`)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        // Continue as long as the string contains `part`
        while (s.length() > 0 && s.find(part) < s.length())
        {
            // Find the starting index of the substring `part`
            size_t pos = s.find(part);

            // Erase the found substring from `s`
            s.erase(pos, part.length());
        }

        // Return the final modified string
        return s;
    }
};

int main()
{
    Solution sol;

    // Example usage
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << sol.removeOccurrences(s, part) << endl;

    return 0;
}
