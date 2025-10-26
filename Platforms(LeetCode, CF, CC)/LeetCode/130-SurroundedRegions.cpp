
/*
================================================================================
PROBLEM: Surrounded Regions (LeetCode 130)
================================================================================

DESCRIPTION:
Given an m x n matrix board containing 'X' and 'O', capture all regions that
are surrounded by 'X'. A region is captured by flipping all 'O's into 'X's.

A region is surrounded if:
- It consists of connected 'O' cells (horizontally or vertically adjacent)
- None of the 'O' cells in the region touch the board's edge


================================================================================
APPROACH: Reverse Thinking with DFS
================================================================================

INTUITION:
Instead of finding surrounded regions, we find UNSURROUNDED regions:
1. Any 'O' on the border cannot be captured
2. Any 'O' connected to a border 'O' cannot be captured
3. All other 'O's must be surrounded and should be captured

ALGORITHM:
1. Mark all border 'O's and their connected 'O's with a temporary marker ('1')
2. Convert all remaining 'O's to 'X' (these are surrounded)
3. Convert all '1's back to 'O' (these are unsurrounded)

TIME COMPLEXITY: O(n * m) - visit each cell at most once
SPACE COMPLEXITY: O(n * m) - worst case recursion depth for DFS

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m; // Board dimensions: n = rows, m = columns

private:
    void dfs(int x, int y, vector<vector<char>> &board)
    {
        // Base case 1: Check boundaries
        if (x < 0 || x >= n || y < 0 || y >= m)
            return;
        
        // Base case 2: Stop at 'X' or already visited cells ('1')
        if (board[x][y] == 'X' || board[x][y] == '1')
            return;

        // Mark this 'O' as safe (connected to border)
        board[x][y] = '1';

        // Direction vectors: right, left, down, up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Explore all 4 adjacent cells
        for (int i = 0; i < 4; i++)
            dfs(x + dx[i], y + dy[i], board);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        m = board[0].size();

        // STEP 1: Mark all border 'O's and connected regions
        
        // Check left (column 0) and right (column m-1) borders
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, board);       // Left border
            dfs(i, m - 1, board);   // Right border
        }

        // Check top (row 0) and bottom (row n-1) borders
        for (int i = 0; i < m; i++)  // IMPORTANT: Use m (columns), not n
        {
            dfs(0, i, board);       // Top border
            dfs(n - 1, i, board);   // Bottom border
        }

        // STEP 2 & 3: Final conversion
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '1')
                    board[i][j] = 'O';  // Restore safe 'O's
                else
                    board[i][j] = 'X';  // Capture surrounded 'O's
            }
        }
    }
};


int main()
{
    Solution s;
    
    // Test case
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    
    s.solve(board);
    
    // Print result
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << "\n";
    }
    
    return 0;
}