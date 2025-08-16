// Time Complexity: O(n log n)
//   - Building the max heap takes O(n).
//   - Each of the (n-1) operations involves two pop() and at most one push(), each O(log n).
//   - So total = O(n log n).
// Space Complexity: O(n)
//   - Priority queue stores at most n elements.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        // Use a max heap to always get the heaviest stones first
        priority_queue<int> pq;
        for (auto i : stones)
            pq.push(i);

        // Keep smashing until 0 or 1 stone left
        while (pq.size() > 1)
        {
            int s1 = pq.top(); // heaviest stone
            pq.pop();
            int s2 = pq.top(); // 2nd heaviest stone
            pq.pop();

            // If they are not equal, push the difference back
            if (s1 > s2)
                pq.push(s1 - s2);
        }

        // If no stones left, return 0
        if (pq.empty())
            return 0;

        // Otherwise return the last stone
        return pq.top();
    }
};

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution sol;
    cout << sol.lastStoneWeight(stones) << endl;
    return 0;
}
