/* TIME & SPACE COMPLEXITY:
   - Time: O(n*m) - visit each pixel at most once
   - Space: O(n*m) - recursion stack in worst case (all pixels same color)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Direction arrays for 4-directional movement (Up, Down, Left, Right)
    int dx[4] = {1, -1, 0, 0}; // Row changes: Down, Up, Stay, Stay
    int dy[4] = {0, 0, 1, -1}; // Column changes: Stay, Stay, Right, Left

    // DFS function to perform flood fill recursively
    void dfs(int sr, int sc, vector<vector<int>> &image, int clr, int sourceColor)
    {
        // Step 1: Change current pixel to new color
        image[sr][sc] = clr;

        // Get grid dimensions for boundary checking
        int n = image.size();    // Number of rows
        int m = image[0].size(); // Number of columns

        // Step 2: Explore all 4 adjacent directions
        for (int i = 0; i < 4; i++)
        {
            // Calculate new coordinates
            int nr = sr + dx[i]; // New row
            int nc = sc + dy[i]; // New column

            // Step 3: Check if new position is valid and has original color
            if (nr >= 0 &&                   // Not above grid boundary
                nc >= 0 &&                   // Not left of grid boundary
                nr < n &&                    // Not below grid boundary
                nc < m &&                    // Not right of grid boundary
                image[nr][nc] == sourceColor // Has the original color to change
            )
            {
                // Step 4: Recursively flood fill the adjacent pixel
                dfs(nr, nc, image, clr, sourceColor);
            }
        }
    }

public:
    // Main flood fill function
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        // Store the original color of the starting pixel
        int mainColor = image[sr][sc];

        // Edge case: If target color is same as original, no change needed
        // This prevents infinite recursion
        if (mainColor == color)
            return image;

        // Start DFS flood fill from the given position
        dfs(sr, sc, image, color, mainColor);

        // Return the modified image
        return image;
    }
};

// Test function to demonstrate the flood fill
void printImage(const vector<vector<int>> &image, const string &title)
{
    cout << title << ":\n";
    for (const auto &row : image)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    Solution solution;

    // Test Case: Standard flood fill
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout << "=== Test Case 1 ===\n";
    printImage(image1, "Original Image");

    vector<vector<int>> result1 = solution.floodFill(image1, 1, 1, 2);
    printImage(result1, "After Flood Fill (sr=1, sc=1, color=2)");

    return 0;
}