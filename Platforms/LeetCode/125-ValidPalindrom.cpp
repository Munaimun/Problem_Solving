/*
    Problem: Valid Palindrome
    Approach: Two-pointer technique with alphanumeric filtering
    Time Complexity: O(n)
        - We traverse each character in the string at most once.
    Space Complexity: O(1)
        - We use constant extra space (only a few pointers and temp variables).
        - No additional data structures are used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlphaNu(char c)
    {
        if ((c >= '0' && c <= '9') || (tolower(c) >= 'a' && tolower(c) <= 'z'))
        {
            return true;
        }

        return false;
    }

    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            if (!isAlphaNu(s[i]))
            {
                i++;
                continue;
            }
            if (!isAlphaNu(s[j]))
            {
                j--;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    string s1 = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(s1) ? "true" : "false") << endl; // Output: true

    // Test case 2
    string s2 = "race a car";
    cout << (sol.isPalindrome(s2) ? "true" : "false") << endl; // Output: false

    // Test case 3 (edge case)
    string s3 = " ";
    cout << (sol.isPalindrome(s3) ? "true" : "false") << endl; // Output: true

    return 0;
}
