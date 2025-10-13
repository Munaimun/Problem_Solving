/*
Problem: Shortest Bridge
------------------------
You are given a binary grid where 1 represents land and 0 represents water.
There are exactly two islands in the grid (two groups of connected 1s).
You need to connect these two islands by flipping 0s into 1s, such that the
number of 0s you flip (the bridge length) is minimized.

Approach:
----------
 1. **DFS (Depth-First Search)** → Find and mark the first island.
   - Convert all its '1's to '2' (to mark them visited).
   - This helps to differentiate between the two islands.

 2. **BFS (Breadth-First Search)** → Expand from the first island.
   - Start BFS from all '2' cells.
   - Move level by level through water cells (0s), turning them into '2's.
   - The first time we reach another '1' (second island), we get the shortest bridge.

*/

/*
Time Complexity: O(N²)
--------------------------
- DFS explores each cell once → O(N²)
- BFS may visit every cell → O(N²)
Total → O(N²)

Space Complexity: O(N²)
----------------------------
- Recursion stack (DFS) + Queue (BFS)
- Both can hold at most N² elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper DFS to mark the first island with '2'
    void dfs(int x, int y, int n, vector<vector<int>> &grid)
    {
        grid[x][y] = 2; // mark visited
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x, ny = dy[i] + y;

            // Continue DFS if adjacent cell is part of the same island (1)
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1)
                dfs(nx, ny, n, grid);
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

        bool flag = false; // to ensure DFS runs only once

        // Step 1: Find and mark the first island using DFS
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    dfs(i, j, n, grid);
                    flag = true;
                    break;
                }
            if (flag)
                break;
        }

        // Step 2: Push all '2' (first island) cells into queue for BFS
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    q.push({i, j, 0}); // x, y, distance
        }

        int ans = n * n; // max possible distance
        while (!q.empty())
        {
            vector<int> u = q.front();
            q.pop();

            int x = u[0], y = u[1], curLevel = u[2];

            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x, ny = dy[i] + y;

                // Stay inside bounds and skip visited cells
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 2)
                {
                    int nextLevel = curLevel + 1;

                    // If reached the second island → update answer
                    if (grid[nx][ny] == 1)
                        ans = min(ans, nextLevel);

                    // Mark as visited and continue expanding
                    grid[nx][ny] = 2;
                    q.push({nx, ny, nextLevel});
                }
            }
        }

        return ans - 1; // subtract 1 because we count one extra layer
    }
};

int main()
{
    // Example usage (not necessary for online judge):
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    Solution sol;
    cout << sol.shortestBridge(grid); // Output: 2
    return 0;
}
