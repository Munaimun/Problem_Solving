// Time Complexity: O(n)
// - Each character is visited at most twice (once by `i`, once by `j`), so it's linear.
// Space Complexity: O(k)
// - At most k unique characters are stored in the unordered_set, where k is the character set size.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> charSet; // to store unique characters in current window

        int i = 0, j = 0, maxLen = 0;

        while (i < s.size())
        {
            // If s[i] is not a duplicate
            if (charSet.find(s[i]) == charSet.end())
            {
                charSet.insert(s[i]);            // add unique character
                maxLen = max(maxLen, i - j + 1); // update max length
                i++;                             // expand the window
            }
            else
            {
                charSet.erase(s[j]); // remove leftmost character
                j++;                 // shrink window from the left
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb");

    return 0;
}
