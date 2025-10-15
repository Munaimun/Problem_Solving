/*
Time Complexity: O(n)
  - Each diagonal is processed in a single loop of length n.
  - Overall, two loops of size n → O(n).

Space Complexity: O(n^2)
  - The matrix of size n x n is stored in memory.
  - No extra significant space used aside from input matrix.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n][n]; // Declare a 2D array of size n x n

    // Input the elements of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    int pri = 0, sec = 0; // Variables to store sums of primary and secondary diagonals

    // Calculate the sum of the primary diagonal (top-left to bottom-right)
    for (int i = 0; i < n; i++)
    {
        pri += arr[i][i];
    }

    // Calculate the sum of the secondary diagonal (top-right to bottom-left)
    for (int i = 0; i < n; i++)
        sec += arr[i][n - 1 - i];

    // Output the absolute difference between the two diagonal sums
    cout << abs(pri - sec) << "\n";

    return 0;
}
