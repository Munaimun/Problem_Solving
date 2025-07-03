// Time Complexity: O(m * n), where m = number of customers, n = number of accounts per customer
// Space Complexity: O(1), as only constant extra space is used

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = 0; // stores the maximum wealth found so far

        for (int i = 0; i < accounts.size(); i++)
        {
            int sum = 0; // sum of wealth for the current customer

            // iterate over each account of the current customer
            for (int j = 0; j < accounts[i].size(); j++)
            {
                sum += accounts[i][j]; // add current account balance to sum
            }

            // update maxWealth if current customer's total is greater
            maxWealth = max(maxWealth, sum);
        }

        return maxWealth; // return the highest wealth among all customers
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> acc = {{1, 2, 3}, {3, 2, 1}};

    cout << sol.maximumWealth(acc) << endl;
}
