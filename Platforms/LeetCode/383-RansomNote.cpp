/**
 * Time Complexity O(m + n)
 * m is the size of ransomeNote, n is the size of magazine
 *
 * Space Complexity O(1)(constant)
 * We use a unordered_map<char, int> to store frequencies.
 * But the character set is limited to 26 lowercase English letters ('a' to 'z').
 * So, even though it's a hashmap, the number of unique keys is constant → O(1) space.
 */

//
// Space Complexity O(1)(constant)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> freq;

        // Count frequency of each character in magazine
        for (char c : magazine)
            freq[c]++;

        // Try to construct ransomNote from magazine
        for (char c : ransomNote)
        {
            if (freq[c] == 0)
                return false;
            freq[c]--;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << boolalpha << sol.canConstruct(ransomNote, magazine) << endl;
    return 0;
}
