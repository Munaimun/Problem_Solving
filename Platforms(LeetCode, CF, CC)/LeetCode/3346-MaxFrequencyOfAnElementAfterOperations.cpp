#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        unordered_map<int, int> cnt;  // count of each element in original array
        map<int, int> diff;           // difference array for sweep line
        
        // For each number, mark the range [num-k, num+k] where it can reach
        for (int x : nums)
        {
            cnt[x]++;
            diff[x];              // ensure x exists in diff map
            diff[x - k]++;        // start of range: increment
            diff[x + k + 1]--;    // end of range: decrement
        }
        
        int ans = 0;
        int adjustable = 0;  // running sum of how many elements can reach current value
        
        // Sweep through all candidate values
        for (auto &[x, delta] : diff)
        {
            adjustable += delta;  // update running count
            
            // For value x:
            // - cnt[x] elements are already at x (no operation needed)
            // - (adjustable - cnt[x]) elements can be adjusted to x
            // - We can use at most numOperations
            ans = max(ans, min(adjustable, cnt[x] + numOperations));
        }
        
        return ans;
    }
};
