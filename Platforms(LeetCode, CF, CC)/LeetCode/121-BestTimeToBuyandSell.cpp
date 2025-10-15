#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int bestBuy = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
            bestBuy = min(bestBuy, prices[i]); // 🛠 Also fix here: use min instead of max
        }

        return maxProfit;
    }
};

int main()
{
    Solution sol;
    int arr[5] = {7, 6, 4, 3, 1};
    vector<int> prices(arr, arr + 5); // convert array to vector

    cout << sol.maxProfit(prices) << endl;
    return 0;
}
