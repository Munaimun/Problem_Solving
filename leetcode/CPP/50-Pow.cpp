// TC: O(logn)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        long binForm =
            n; // Store exponent as long to safely handle INT_MIN (-2^31) case

        // If exponent is negative, convert to positive and take reciprocal of
        // base
        if (n < 0)
        {
            x = 1 / x;
            binForm = -binForm; // Convert negative exponent to positive for
                                // processing
        }

        double ans = 1.0; // Initialize result to 1 (multiplicative identity)

        // Binary exponentiation loop
        while (binForm > 0)
        {
            // If current bit is set (odd), include current x in result
            if (binForm % 2 == 1)
            {
                ans *= x;
            }

            x *= x;       // Square the base for next bit
            binForm /= 2; // Move to the next bit (right shift equivalent)
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    cout << sol.myPow(2.10, 3) << "\n";
}