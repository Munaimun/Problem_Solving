/*
      Time Complexity: O(n)
      - We iterate through the string once to build the frequency map → O(n)
      - Then iterate through the map (at most 52 characters for upper/lowercase letters) → O(1)
      - So total: O(n)

      Space Complexity: O(1)
      - Frequency map stores at most 52 unique characters (a-z, A-Z), which is constant
      - So space is O(1) despite using a hashmap
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> fre;

        // step 1: check the frequency of all character
        for (auto c : s)
            fre[c]++;

        int res = 0; // to store the length
        bool hasOdd = false;
        for (auto &entry : fre)
        {
            int freq = entry.second; // taking the value from the map

            if (freq % 2 == 0)
                res += freq;
            else
            {
                res += freq - 1;
                hasOdd = true;
            }
        }

        // If hasOddFrequency is true, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (hasOdd)
            return res + 1;

        return res;
    }
};

int main()
{
    Solution s;

    cout << s.longestPalindrome("abccccdd") << endl;

    return 0;
}