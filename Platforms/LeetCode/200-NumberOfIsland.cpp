#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Number of Islands
 * 
 * Description:
 * Given a 2D grid of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically.
 * 
 * Approach:
 * - Use Depth First Search (DFS) to traverse and mark all connected land cells
 * - Iterate through each cell in the grid
 * - When we find an unvisited land cell ('1'), we start a DFS to mark all 
 *   connected land cells as visited (change to '#')
 * - Each DFS call represents one complete island
 * - Count the number of DFS calls to get the total number of islands
 * 
 * Time Complexity: O(n * m)
 * - We visit each cell in the grid exactly once
 * - n = number of rows, m = number of columns
 * - Even though DFS is called recursively, each cell is marked as visited ('#')
 *   and never processed again
 * 
 * Space Complexity: O(n * m)
 * - Recursion stack space in worst case when the entire grid is filled with land ('1's)
 * - In worst case, DFS will go as deep as n*m cells
 * - No extra data structures are used apart from the recursion stack
 */

class Solution
{
public:
    // DFS function to mark all connected land cells starting from (x, y)
    // Marks current cell and recursively visits all adjacent land cells
    void dfs(int x, int y, int n, int m, vector<vector<char>> &grid)
    {
        // Mark current cell as visited
        grid[x][y] = '#';

        // Direction arrays for moving up, down, left, right
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        // Explore all 4 adjacent directions
        for (int i = 0; i < 4; i++)
        {
            int nr = x + dx[i], nc = y + dy[i];

            // Check if the neighbor is valid and is unvisited land
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '1')
                dfs(nr, nc, n, m, grid);
        }
    }

    // Main function to count the number of islands
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        
        // Iterate through each cell in the grid
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                // If we find unvisited land, it's a new island
                if (grid[x][y] == '1')
                {
                    // Mark all cells of this island using DFS
                    dfs(x, y, n, m, grid);
                    // Increment island count
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    
    // Example 1: Grid with 1 island
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    
    cout << "Number of islands: " << sol.numIslands(grid1) << endl;
    // Expected output: 1


    return 0;
}