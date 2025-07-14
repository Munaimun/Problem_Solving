// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary (excluding output array)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        cout << "len: " << n << "\n";

        // Initialize answer array with 1s
        vector<int> ans(n, 1);

        // First pass (left to right): build prefix product
        // ans[i] will contain the product of all elements to the left of index i
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i - 1];

        // Initialize suffix product (product of elements to the right)
        int suffix = 1;

        // Second pass (right to left): multiply suffix to the current ans[i]
        for (int i = n - 2; i >= 0; i--)
        {
            suffix *= nums[i + 1]; // update suffix product
            ans[i] *= suffix;      // combine prefix and suffix
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Solution sol;
    vector<int> output = sol.productExceptSelf(arr);

    // Print the result
    for (int val : output)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
