#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int sum = 0;
    while (n--)
    {
        int i;
        cin >> i;

        if (i == x || i < x)
            sum += i;
    }
    cout << sum << endl;
    return 0;
}