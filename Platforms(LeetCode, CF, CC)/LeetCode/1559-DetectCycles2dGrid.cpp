// LeetCode 1559: Detect Cycles in 2D Grid
// ----------------------------------------
// Problem: Find if there's a cycle of same-valued cells in a 2D grid
// A cycle must have length >= 4 and can't immediately backtrack
//
// Approach: DFS with parent tracking
// - Start DFS from each unvisited cell
// - Move only to adjacent cells with same value
// - Track parent to avoid immediate backtracking
// - If we hit an already visited cell (not parent) → cycle found!
//
// Time Complexity: O(m * n)
//   - We visit each cell at most once
//   - For each cell, we check 4 directions
//
// Space Complexity: O(m * n)
//   - Visited array takes O(m * n)
//   - Recursion stack can go up to O(m * n) in worst case

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // the four direction to change the cell
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &isVisited, int row, int col, int parRow, int parCol, char ch, int n, int m)
    {
        isVisited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            // calculating the next cell to compare
            int nextRow = row + dx[i], nextCol = col + dy[i];

            // validating the next cell and move forwar only when the next cell's character is same
            if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && grid[nextRow][nextCol] == ch)
            {
                // skip if this is the parent cell
                if (nextRow == parRow && nextCol == parCol)
                    continue;

                // if it is visited that means there is a cycle
                if (isVisited[nextRow][nextCol])
                    return true;

                // Continue DFS from the new cell
                if (dfs(grid, isVisited, nextRow, nextCol, row, col, ch, n, m))
                    return true;
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> isVisited(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!isVisited[i][j]) // if the cell is ot visited
                {
                    // if cycle found will return true
                    if (dfs(grid, isVisited, i, j, -1, -1, grid[i][j], n, m))
                        return true;
                }
            }
        }

        return false;
    }
};

// Test the solution
int main()
{
    Solution sol;

    // Test case 1: Cycle exists
    vector<vector<char>> grid1 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}};
    cout << "Test 1 - Has cycle: " << (sol.containsCycle(grid1) ? "true" : "false") << endl;

    // Test case 2: No cycle
    vector<vector<char>> grid2 = {
        {'c', 'c', 'c', 'a'},
        {'c', 'd', 'c', 'c'},
        {'c', 'c', 'e', 'c'},
        {'f', 'c', 'c', 'c'}};
    cout << "Test 2 - Has cycle: " << (sol.containsCycle(grid2) ? "true" : "false") << endl;

    // Test case 3: Simple cycle
    vector<vector<char>> grid3 = {
        {'a', 'a'},
        {'a', 'a'}};
    cout << "Test 3 - Has cycle: " << (sol.containsCycle(grid3) ? "true" : "false") << endl;

    return 0;
}