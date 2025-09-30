/*
Problem: LeetCode 1306 - Jump Game III
Algorithm: DFS (Depth-First Search) with backtracking

Approach:
- Start from the given index and explore all possible jumps
- From index i, we can jump to either i + arr[i] or i - arr[i]
- Use DFS to explore both directions and check if we can reach any index with value 0
- Mark visited indices to avoid infinite loops and redundant exploration
- Return true as soon as we find an index with value 0

Time Complexity: O(n)
- Each index is visited at most once due to the isVisited array
- We explore at most 2 directions from each index
- Total operations: O(n)

Space Complexity: O(n)
- isVisited array: O(n)
- Recursion stack depth in worst case: O(n)
- Total: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // DFS helper function to explore all reachable indices from current position
    bool dsf(int u, int n, vector<bool> &isVisited, vector<int> &arr)
    {
        // Base case: If current index has value 0, we've reached our goal
        if (arr[u] == 0)
            return true;
        
        // Mark the current index as visited to avoid cycles
        isVisited[u] = true;

        // Try jumping forward: current_index + arr[current_index]
        int v = u + arr[u];
        // Check if forward jump is within bounds and not visited yet
        if (v < n && !isVisited[v])
        {
            // Recursively explore from the new position
            if (dsf(v, n, isVisited, arr))
                return true;
        }

        // Try jumping backward: current_index - arr[current_index]
        v = u - arr[u];
        // Check if backward jump is within bounds and not visited yet
        if (v >= 0 && !isVisited[v])
        {
            // Recursively explore from the new position
            if (dsf(v, n, isVisited, arr))
                return true;
        }

        // If neither direction leads to a 0, return false
        return false;
    }

    // Main function to check if we can reach any index with value 0
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size(); // Get array size
        vector<bool> isVisited(n, false); // Track visited indices to prevent cycles

        // Start DFS traversal from the given start index
        return dsf(start, n, isVisited, arr);
    }
};

int main()
{
    Solution solution;
    
    // Test case 1: Can reach index 3 with value 0
    vector<int> arr1 = {4, 2, 3, 0, 3, 1, 2};
    int start1 = 5;
    cout << "Test 1 - Expected: 1 (true), Got: " << solution.canReach(arr1, start1) << endl;
    
    // Test case 2: Cannot reach any index with value 0
    vector<int> arr2 = {4, 2, 3, 0, 3, 1, 2};
    int start2 = 0;
    cout << "Test 2 - Expected: 1 (true), Got: " << solution.canReach(arr2, start2) << endl;
    
    // Test case 3: Cannot reach index with value 0
    vector<int> arr3 = {3, 0, 2, 1, 2};
    int start3 = 2;
    cout << "Test 3 - Expected: 0 (false), Got: " << solution.canReach(arr3, start3) << endl;
    
    // Test case 4: Start position itself has value 0
    vector<int> arr4 = {0, 1};
    int start4 = 0;
    cout << "Test 4 - Expected: 1 (true), Got: " << solution.canReach(arr4, start4) << endl;

    return 0;
}