#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n)
    - First loop marks presence using negation: O(n)
    - Second loop collects missing numbers: O(n)

    Space Complexity: O(1) (ignoring the output vector)
    - No extra space used other than the result vector
    - Input array is modified in-place
*/

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // Step 1: Mark indices corresponding to existing numbers as negative
        for (int num : nums)
        {
            int index = abs(num) - 1; // Convert number to index (1-based to 0-based)
            if (nums[index] > 0)      // Only negate if not already negative
                nums[index] = -nums[index];
        }

        vector<int> res;

        // Step 2: The indices with positive values correspond to missing numbers
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                res.push_back(i + 1); // i + 1 is the missing number (1-based)
        }

        return res;
    }
};

int main()
{
    Solution s;

    vector<int> n = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = s.findDisappearedNumbers(n);

    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}
