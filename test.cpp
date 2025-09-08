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

        int ans = INT_MAX;
        // Try all possible numbers of 3-flower bundles
        for (int three = 0; three <= n / 3; three++)
        {
            int flowersFromThree = three * 3;
            int remaining = n - flowersFromThree;

            cerr << "[three=" << three
                 << "] flowersFromThree=" << flowersFromThree
                 << ", remaining=" << remaining;

            if (remaining % 2 == 0)
            {
                int two = remaining / 2;
                int cost = three * 5 + two * 4;
                cerr << ", two=" << two << ", cost=" << cost << "\n";
                ans = min(ans, cost);
            }
            else
            {
                cerr << " (skip, not divisible by 2)\n";
            }
        }

        cout << ans << "\n";
    }
}
