/**
 * Time Complexity: O(n) - where n is the number of elements in the height array.
 *
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int lp = 0, rp = n - 1; // Two pointers: left and right

        int curWater = 0, maxWater = 0; // Track current and maximum area

        while (lp < rp)
        {
            // Height is determined by the shorter line
            int h = min(height[lp], height[rp]);

            // Width is the distance between the two pointers
            int w = rp - lp;

            // Calculate the current area and update max if it's greater
            curWater = h * w;
            maxWater = max(maxWater, curWater);

            // Move the pointer pointing to the shorter line inward
            // This helps explore potentially taller lines for larger area
            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxWater; // Return the maximum area found
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << sol.maxArea(arr) << endl;
    return 0;
}
