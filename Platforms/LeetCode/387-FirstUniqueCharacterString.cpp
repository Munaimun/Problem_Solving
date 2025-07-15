/*
Time Complexity:  O(n)
  - Iterate through the string twice: once to build frequency map, once to find first unique character.
Space Complexity: O(1)
  - Uses fixed-size frequency array of length 26, regardless of input size.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();
        vector<int> freq(26, 0); // Frequency array for all lowercase English letters

        // Count the frequency of each character in the string
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        // Identify the first character with frequency 1
        for (int i = 0; i < n; i++)
        {
            if (freq[s[i] - 'a'] == 1)
                return i; // Return the index of first unique character
        }

        // If no unique character found, return -1
        return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.firstUniqChar("leetcode") << endl;
    return 0;
}
