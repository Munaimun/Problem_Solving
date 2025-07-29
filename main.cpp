#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<int>> newArr(n, vector<int>(n));

    // input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    // top row
    for (int i = 0; i <= n - 2; i++)
        newArr[0][i + 1] = arr[0][i];

    // right column
    for (int i = 0; i <= n - 2; i++)
        newArr[i + 1][n - 1] = arr[i][n - 1];

    // bottom row
    for (int i = 1; i <= n - 1; i++)
        newArr[n - 1][i - 1] = arr[n - 1][i];

    // left column
    for (int i = 1; i <= n - 2; i++)
        newArr[i - 1][0] = arr[i][0];

    // copy inner values
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
            newArr[i][j] = arr[i][j];

    // output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << newArr[i][j];
            if (j < n - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
