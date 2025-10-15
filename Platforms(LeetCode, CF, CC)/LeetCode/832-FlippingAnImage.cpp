/*
 * Time Complexity: O(n * m)
 *    - n: number of rows
 *    - m: number of columns (assumed equal to n here)
 *    We iterate through each element twice: once to reverse and once to invert.
 *
 * Space Complexity: O(1)
 *    - We modify the image in-place without using extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        int n = image.size();

        for (int i = 0; i < n; i++)
        {
            // Flip row horizontally by reversing it
            reverse(image[i].begin(), image[i].end());

            // Invert each bit in the row
            for (int j = 0; j < n; j++)
            {
                image[i][j] = 1 - image[i][j]; // 1->0 and 0->1
            }
        }

        return image;
    }
};

int main()
{
    vector<vector<int>> arr = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};

    Solution sol;

    // Process the image
    vector<vector<int>> res = sol.flipAndInvertImage(arr);

    // Print the output matrix
    for (auto i : res)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]\n";
    }

    return 0;
}
