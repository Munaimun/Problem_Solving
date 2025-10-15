// Time Complexity: O(n) → n = length of s2, each char is processed once
// Space Complexity: O(26) → constant space for frequency arrays

// Commit message: Fix sliding window permutation check and frequency array indexing

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // edge case
        if (s1.size() > s2.size())
            return false;

        // declaring two frequency arrays: 1 for s1, 2 for s2
        vector<int> freq1(26, 0), freq2(26, 0);

        // count the char frequency in s1
        for (auto c : s1)
        {
            freq1[c - 'a']++;
        }

        // build initial window for s2
        for (int i = 0; i < s1.size(); i++)
        {
            freq2[s2[i] - 'a']++;
        }

        // check if initial window contains a permutation
        if (freq1 == freq2)
            return true;

        // slide the window to check further characters
        for (int i = s1.size(); i < s2.size(); i++)
        {
            // add new char to the window
            freq2[s2[i] - 'a']++;

            // remove the leftmost char from the previous window
            freq2[s2[i - s1.size()] - 'a']--;

            // check if current window contains a permutation
            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    string s1 = "ab", s2 = "eidboaoo";

    if (sol.checkInclusion(s1, s2))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
