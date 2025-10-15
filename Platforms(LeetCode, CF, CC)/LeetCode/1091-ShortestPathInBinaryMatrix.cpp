/*
Problem: Shortest Path in Binary Matrix (LeetCode 1091)

You are given an n x n binary matrix `grid`. Each cell can either be:
    - 0 → empty cell (you can move here)
    - 1 → blocked cell (you cannot move here)

You can move in **8 directions** (up, down, left, right, and diagonals) from any cell.
Return the length of the shortest clear path from the **top-left (0,0)** cell
to the **bottom-right (n-1,n-1)** cell.
If there’s no such path, return -1.

Example:
Input:
grid = [
  [0,1],
  [1,0]
]

Output: 2

Explanation:
Path → (0,0) → (1,1) has length 2.

----------------------------------------------------
Time Complexity:  O(n²)   — each cell is visited at most once.
Space Complexity: O(n²)   — for the BFS queue and visited grid.
----------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Directions for 8 possible moves (vertical, horizontal, diagonal)
        int dx[] = {+1, -1, 0, 0, -1, +1, -1, +1};
        int dy[] = {0, 0, -1, +1, +1, -1, -1, +1};

        // If start or end cell is blocked, no path is possible
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // Special case: 1x1 grid and it's open
        if (n == 1)
            return 1;

        // BFS queue holds (x, y, distance or level)
        queue<vector<int>> q;
        q.push({0, 0, 1}); // Start from (0,0) with distance = 1
        grid[0][0] = 1;    // Mark visited

        while (!q.empty())
        {
            vector<int> cur = q.front();
            q.pop();

            int x = cur[0], y = cur[1], curLevel = cur[2];

            // Explore all 8 directions
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Valid cell and not visited
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0)
                {
                    // Update next level distance
                    int nextLevel = curLevel + 1;
                    grid[nx][ny] = 1; // Mark as visited
                    q.push({nx, ny, nextLevel});

                    // If we've reached bottom-right corner, return path length
                    if (nx == n - 1 && ny == n - 1)
                        return nextLevel;
                }
            }
        }

        // If BFS finishes without reaching the end
        return -1;
    }
};

// Driver code to test the solution
int main()
{
    Solution sol;

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}};

    cout << "Shortest Path Length: " << sol.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}
