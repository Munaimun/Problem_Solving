#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_set<int> seen; // To store all numbers that appear in the array

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seen.insert(x); // Mark number as seen
    }

    // Check from -m to m for the first missing number
    for (int x = -m; x <= m; x++)
    {
        if (seen.find(x) == seen.end())
        {
            cout << x << endl;
            break;
        }
    }

    return 0;
}
