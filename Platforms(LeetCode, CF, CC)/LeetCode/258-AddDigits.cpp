// Time Complexity:
// Each recursive call reduces the number `num` to the sum of its digits.
// - For a number with `d` digits, summing the digits takes O(d).
// - After the first step, the sum is at most 9*d (much smaller).
// - The recursion depth is small (logarithmic in value of num).
// Overall: O(log(num)) in the worst case.

// Space Complexity:
// - Each recursive call adds a frame to the call stack.
// - Depth of recursion is O(log(num)).
// So space complexity is O(log(num)).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        // Base case: if the number is a single digit, return it
        if (num < 10)
            return num;

        int sum = 0, n = num;

        // Extract digits and calculate sum
        while (n > 0)
        {
            sum += n % 10; // take last digit
            n = n / 10;    // remove last digit
        }

        // Recursive call on the digit sum
        return addDigits(sum);
    }
};

int main()
{
    Solution s;
    cout << s.addDigits(38) << endl;

    return 0;
}
