// Time Complexity: O(n log n)
//   - Pushing n elements into a priority_queue takes O(n log n)
//   - Popping and assigning ranks also takes O(n log n)
// Space Complexity: O(n)
//   - Extra vector `ans` and priority_queue storing n elements

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<string> ans(n);

        // Use max-heap priority queue to store {score, index}
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
            pq.push({score[i], i});

        // Assign Gold, Silver, Bronze medals
        if (!pq.empty())
        {
            ans[pq.top().second] = "Gold Medal";
            pq.pop();
        }
        if (!pq.empty())
        {
            ans[pq.top().second] = "Silver Medal";
            pq.pop();
        }
        if (!pq.empty())
        {
            ans[pq.top().second] = "Bronze Medal";
            pq.pop();
        }

        // Assign remaining ranks starting from 4
        int rank = 4;
        while (!pq.empty())
        {
            ans[pq.top().second] = to_string(rank);
            pq.pop();
            rank++;
        }

        return ans;
    }
};

int main()
{
    vector<int> score = {5, 4, 3, 2, 1};
    Solution s;
    vector<string> res = s.findRelativeRanks(score);

    for (auto &str : res)
        cout << str << " ";
    cout << endl;
    return 0;
}
