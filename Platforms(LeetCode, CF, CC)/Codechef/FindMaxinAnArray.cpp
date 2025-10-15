#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int maxH = INT_MIN;

        while (n--)
        {
            int val;
            cin >> val;
            maxH = max(maxH, val);
        }

        cout << maxH << endl;
        }

    return 0;
}
