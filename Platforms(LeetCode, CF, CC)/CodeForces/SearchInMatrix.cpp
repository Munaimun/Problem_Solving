/*
Time Complexity: O(n * m)
  - Iterates through all elements of the matrix once.

Space Complexity: O(1)
  - Uses constant extra space (excluding input matrix).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Declare a 2D array of size n x m to store the matrix elements
    int arr[n][m];

    // Read the full matrix from input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Read the target value to search in the matrix
    int tar;
    cin >> tar;

    // Flag to indicate whether the target was found
    bool flag = false;

    // Traverse the entire matrix to search for the target value
    for (int i = 0; i < n && !flag; i++) // stop outer loop if target found
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == tar)
            {
                flag = true;
                break; // stop inner loop
            }
        }
    }

    // Output based on the presence of the target in the matrix
    cout << (flag ? "will not take number" : "will take number") << "\n";

    return 0;
}
