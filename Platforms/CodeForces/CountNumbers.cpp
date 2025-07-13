#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    // Initialize a frequency array to store the count of numbers from 1 to n
    // Index i of this array represents how many times number i has been added
    vector<int> freq(n + 1, 0);

    // Process each query
    while (q--)
    {
        int a, x;
        cin >> a >> x;

        if (a == 1)
        {
            // Type 1 query: add x to the array (i.e., increase its count)
            freq[x]++;
        }
        else if (a == 2)
        {
            // Type 2 query: print the number of times x has been added
            cout << freq[x] << endl;
        }
    }

    return 0;
}
