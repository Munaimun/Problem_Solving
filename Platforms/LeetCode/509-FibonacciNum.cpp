// Time Complexity: O(2^n)
//   - Because for each call of fib(n), we make two recursive calls: fib(n-1) and fib(n-2).
//   - This creates an exponential growth of calls (like a binary tree of calls).
//   - Example: fib(5) calls fib(4) + fib(3), then fib(4) calls fib(3) + fib(2), and so on.
//   - Many repeated calculations happen (overlapping subproblems).
//
// Space Complexity: O(n)
//   - Due to recursion depth (maximum number of function calls waiting on the call stack).
//   - At most, n function calls exist at the same time (when going down fib(n-1), fib(n-2), etc.).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        // Base case:This stops recursion
        if (n == 1 || n == 0)
            return n;

        // Recursive case:
        // This is the definition of Fibonacci sequence
        int res = fib(n - 1) + fib(n - 2);

        // Return the computed result
        return res;
    }
};

int main()
{
    Solution s;

    cout << s.fib(3) << endl; // Output: 2

    return 0;
}
