/*
 * Time Complexity: O(n * m)
 *   - We check each element (except those in the last row and column) once.
 *
 * Space Complexity: O(1)
 *   - We use no extra space, just a flag for comparison.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns (by checking the first row)

        bool flag = true;

        // Iterate through each element except last row and last column
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                // Check if current element equals its bottom-right neighbor
                if (matrix[i][j] != matrix[i + 1][j + 1])
                {
                    flag = false; // Mismatch found, not a Toeplitz matrix
                    break;
                }
            }
        }

        return flag; // Return the result after checking all diagonals
    }
};

int main()
{
    // Input matrix to test Toeplitz property
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}};

    Solution s;

    cout << s.isToeplitzMatrix(arr) << endl;

    return 0;
}
