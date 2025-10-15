/*
Time Complexity: O(n)
- Each character in the string is visited at most once (during reversal).
- Loop runs in steps of 2k, but we reverse only k characters max in each step.
- So overall linear time in terms of string length.

Space Complexity: O(1)
- Reversals are done in-place using the reverse function.
- No extra space used apart from variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size(); // Store length of the string

        // Traverse the string in blocks of 2k characters
        for (int i = 0; i < n; i += 2 * k)
        {
            // Calculate the end index for reversal (reverse from i to i+k, or until end of string)
            int end = min(i + k, n);

            // Reverse the first k characters of the current 2k block
            reverse(s.begin() + i, s.begin() + end);
        }

        return s;
    }
};

int main()
{
    Solution s;
    string a = "abcdefg";
    int k = 2;

    cout << s.reverseStr(a, k) << endl; // Output: bacdfeg

    return 0;
}
