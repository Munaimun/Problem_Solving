// Time Complexity: O(n)
// - We iterate over each character once to reverse words.
//
// Space Complexity: O(1)
// - In-place reversal; no extra data structures used (excluding input/output).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to reverse each word in a given string
    string reverseWords(string s)
    {
        int i = 0, j = 0, n = s.size();

        // Traverse the string to find words separated by spaces
        while (j <= n)
        {
            // If current character is a space or end of string, reverse the word
            if (j == n || s[j] == ' ')
            {
                // Reverse the word from index i to j-1
                reverse(s.begin() + i, s.begin() + j);

                // Move to the start of the next word
                j++;
                i = j;
            }
            else
            {
                // Expand the end pointer of the current word
                j++;
            }
        }

        return s;
    }
};

int main()
{
    string s = "Mr ding";
    Solution sol;

    // Output: "rM gnid"
    cout << sol.reverseWords(s) << endl;

    return 0;
}
