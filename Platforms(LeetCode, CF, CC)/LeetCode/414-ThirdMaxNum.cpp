// Time Complexity: O(n)
//   - Single pass through the array.
// Space Complexity: O(1)
//   - Only 3 variables used, no extra data structures.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        // Initialize top 3 numbers as LONG_MIN
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (auto num : nums)
        {
            // Skip duplicates
            if (num == first || num == second || num == third)
                continue;

            if (num > first)
            {
                // Shift down first and second
                third = second;
                second = first;
                first = num;
            }
            else if (num > second)
            {
                // Shift down second
                third = second;
                second = num;
            }
            else if (num > third)
            {
                third = num;
            }
        }

        // If less than 3 unique numbers, return the maximum
        return third == LONG_MIN ? first : third;
    }
};

int main()
{
    vector<int> n = {2, 2, 3, 1};
    Solution s;
    cout << s.thirdMax(n) << endl;
    return 0;
}
