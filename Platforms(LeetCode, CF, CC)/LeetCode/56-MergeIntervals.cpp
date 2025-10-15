#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n log n) for sorting + O(n) for merging = O(n log n)
    // Space Complexity: O(n) for storing merged intervals
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0]; // sort based on the first element of each interval
             });

        vector<vector<int>> merged;

        // Step 2: Initialize 'pre' with the first interval
        vector<int> pre = intervals[0];

        // Step 3: Iterate from the second interval to the end
        for (int i = 1; i < n; ++i)
        {
            vector<int> interval = intervals[i];

            // Step 4: If current interval overlaps with 'pre', merge them
            if (interval[0] <= pre[1])
            {
                // Take the max end time of the two overlapping intervals
                pre[1] = max(pre[1], interval[1]);
            }
            else
            {
                // No overlap: push the previous merged interval and update 'pre'
                merged.push_back(pre);
                pre = interval;
            }
        }

        // Step 5: Push the last interval
        merged.push_back(pre);

        return merged;
    }
};

int main()
{
    Solution sol;

    // Input intervals
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}};

    // Call merge function
    vector<vector<int>> result = sol.merge(intervals);

    // Print result
    cout << "Merged Intervals: ";
    for (auto &interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
