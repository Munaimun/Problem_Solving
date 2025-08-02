/*
Time Complexity: O(max(N, M))
    - Where N = length of num1, M = length of num2
    - We iterate once through the longest number

Space Complexity: O(max(N, M))
    - Result string stores up to max(N, M) + 1 digits (in case of carry)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1; // Start from the last digit of num1
        int j = num2.size() - 1; // Start from the last digit of num2
        int carry = 0;           // To store carry during addition
        string res;              // To store result in reverse order

        // Loop while there are digits in either string or a carry remains
        while (i >= 0 || j >= 0 || carry)
        {
            // Convert current digit of num1 to integer, or 0 if i < 0
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            // Convert current digit of num2 to integer, or 0 if j < 0
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;

            int total = digit1 + digit2 + carry; // Sum current digits and carry
            carry = total / 10;                  // Calculate carry for next iteration

            // Append the current digit to result as a character
            res.push_back((total % 10) + '0');

            --i; // Move to next digit to the left in num1
            --j; // Move to next digit to the left in num2
        }

        // Reverse result since we built it from least significant digit to most
        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution s;
    string num1 = "11", num2 = "123";
    cout << s.addStrings(num1, num2) << endl;

    return 0;
}
