/*
 *
 * Time Complexity: O(N!)
 * - In worst case, we try placing queens in all possible positions
 * - First row has N choices, second has ~(N-1), third ~(N-2), etc.
 *
 * Space Complexity: O(N²)
 * - Board representation takes O(N²) space
 * - Recursion depth is O(N) for N rows
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Checks if placing a queen at (row, col) is safe from attacks
     * Validates horizontal, vertical, and both diagonal directions
     */
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        /**
         * @param col: passing this from Nqueens function as i
         */

        // Check horizontally (left side of current position)
        for (int c = 0; c < col; c++)
            if (board[row][c] == 'Q')
                return false;

        // Check vertically (upper side of current position)
        for (int r = 0; r < row; r++)
            if (board[r][col] == 'Q')
                return false;

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        // No conflicts found, position is safe
        return true;
    }

    /**
     * Recursively places queens row by row using backtracking
     * Tries all possible column positions for each row
     */
    void NQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
    {
        // Base case: all queens placed successfully
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        // Try placing queen in each column of current row
        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col, n))
            {
                // Place queen at current position
                board[row][col] = 'Q';

                // Recursively solve for next row
                NQueens(board, row + 1, n, ans);

                // Backtrack: remove queen and try next position
                board[row][col] = '.';
            }
        }
    }

    /**
     * Main function to solve N-Queens problem
     * Returns all possible arrangements of N queens on NxN board
     */
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize NxN board with dots

        // Start backtracking from row 0
        NQueens(board, 0, n, ans);

        return ans;
    }
};

int main()
{
    Solution solver;
    int n = 4;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    cout << "Total solutions for " << n << "-Queens: " << solutions.size() << endl;

    // Print first solution if exists
    if (!solutions.empty())
    {
        cout << "\nFirst solution:" << endl;
        for (const string &row : solutions[0])
        {
            cout << row << endl;
        }
    }

    return 0;
}