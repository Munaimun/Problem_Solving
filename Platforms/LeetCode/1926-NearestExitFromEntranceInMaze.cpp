// Problem Statement:
// You are given a maze represented as a 2D grid of characters. Each cell is either:
// '.' (an empty cell) or '+' (a wall).
// You are also given the coordinates of an entrance in the maze.  
// Your task is to find the **minimum number of steps** required to reach the **nearest exit** from the entrance.  
// An exit is any empty cell on the border of the maze **other than the entrance itself**.  
// If no exit can be reached, return -1.
//
// Example:
// Input:
// maze = [
//   ['+','+','.','+'],
//   ['.','.','.','+'],
//   ['+','+','+','.']
// ]
// entrance = [1,2]
// Output: 1
//
// Explanation: The nearest exit is at cell (1,3), which is reachable in 1 step.
//
// ------------------------------------------------------------
//
// Time Complexity: O(N * M)
// Each cell is visited at most once during the BFS traversal.
//
// Space Complexity: O(N * M)
// Due to the queue and visited cells in the maze.
//
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        // Direction vectors: down, up, right, left
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int n = maze.size();
        int m = maze[0].size();

        // Queue stores {x, y, distance_from_start}
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});

        // Mark the entrance as visited
        maze[entrance[0]][entrance[1]] = '+';

        int ans = n * m; // Initialize with a large value

        while (!q.empty())
        {
            vector<int> cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int curLevel = cur[2];

            // Explore 4 possible directions
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                // Check if the next position is inside the maze and not a wall
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.')
                {
                    int nextLevel = curLevel + 1;
                    maze[nx][ny] = '+'; // Mark visited

                    // If it's on the border, it's an exit
                    if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1)
                        ans = min(ans, nextLevel);

                    q.push({nx, ny, nextLevel});
                }
            }
        }

        // If ans is unchanged, no exit was found
        if (ans == n * m)
            return -1;
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};

    cout << "Nearest Exit Steps: " << sol.nearestExit(maze, entrance) << endl;

    return 0;
}