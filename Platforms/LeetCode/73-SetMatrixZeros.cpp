//doc
#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Given an m x n matrix, if an element is 0, set its entire row and column to 0.
    Requirement: Do it in-place (without extra space for row/column markers)

    Approach: 
    - Use the first row and first column as markers to indicate which rows/columns should be zeroed.
    - Handle first row and first column separately because they are used as markers.
    
    Time Complexity: O(n * m)
        - We traverse the matrix multiple times, each taking O(n*m)
    Space Complexity: O(1)
        - Only two boolean variables used, no extra arrays
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns

        bool rowImpacted = false; // whether first row contains 0
        bool colImpacted = false; // whether first column contains 0

        // Check if the first row has any 0
        for (int col = 0; col < m; col++)
            if (matrix[0][col] == 0)
            {
                rowImpacted = true;
                break;
            }

        // Check if the first column has any 0
        for (int row = 0; row < n; row++)
            if (matrix[row][0] == 0)
            {
                colImpacted = true;
                break;
            }

        // Use first row and column as markers
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // mark this row
                    matrix[0][j] = 0; // mark this column
                }
            }
        }

        // Set zeros based on the markers
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Set the first row to zeros if needed
        if (rowImpacted)
        {
            for (int i = 0; i < m; i++)
                matrix[0][i] = 0;
        }

        // Set the first column to zeros if needed
        if (colImpacted)
        {
            for (int j = 0; j < n; j++)
                matrix[j][0] = 0;
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};

    Solution().setZeroes(matrix);

    // Print the result
    for (auto &row : matrix)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}

/*
Commit Message:
Implement optimal in-place solution for Set Matrix Zeroes problem
- Uses first row and column as markers to reduce extra space to O(1)
- Handles first row and first column separately
- Time Complexity: O(n*m), Space Complexity: O(1)
*/
