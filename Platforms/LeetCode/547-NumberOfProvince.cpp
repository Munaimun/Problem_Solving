/*
Problem: LeetCode 547 - Number of Provinces
Algorithm: DFS (Depth-First Search) to find connected components

Approach:
- Treat the problem as finding connected components in an undirected graph
- Each city is a node, and isConnected matrix represents adjacency
- Use DFS to traverse all cities in a province and mark them visited
- Count how many times we initiate a new DFS (each initiation = new province)

Time Complexity: O(n²)
- We iterate through n cities in the main loop: O(n)
- For each unvisited city, DFS explores all n connections in worst case
- Each city is visited exactly once, but we check the adjacency matrix: O(n²)

Space Complexity: O(n)
- isVisited array: O(n)
- Recursion stack depth in worst case (all cities in one province): O(n)
- Total: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // DFS helper function to mark all cities in the current province as visited
    void dfs(int u, vector<bool> &isVisited, int n, vector<vector<int>> &isConnected)
    {
        // Mark the current city as visited
        isVisited[u] = 1;

        // Explore all cities connected to the current city
        for (int v = 0; v < n; v++)
        {
            // If city v is connected to city u AND city v is not yet visited
            if (isConnected[u][v] && !isVisited[v])
            {
                // Recursively visit city v and all cities connected to it
                dfs(v, isVisited, n, isConnected);
            }
        }
    }

    // Main function to count the number of provinces
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(); // Number of cities
        vector<bool> isVisited(n, 0); // Track visited cities (initially all false)

        int ans = 0; // Counter for number of provinces

        // Iterate through all cities
        for (int i = 0; i < n; i++)
        {
            // If city i hasn't been visited yet, it's a new province
            if (!isVisited[i])
            {
                // Perform DFS to mark all cities in this province
                dfs(i, isVisited, n, isConnected);
                ans++; // Increment province count
            }
        }

        return ans; // Return total number of provinces
    }
};

int main()
{
    Solution solution;
    
    // Test case 1: Two provinces
    vector<vector<int>> isConnected1 = {{1, 1, 0}, 
                                         {1, 1, 0}, 
                                         {0, 0, 1}};
    cout << "Test 1 - Expected: 2, Got: " << solution.findCircleNum(isConnected1) << endl;
    
    // Test case 2: Three provinces (no connections)
    vector<vector<int>> isConnected2 = {{1, 0, 0}, 
                                         {0, 1, 0}, 
                                         {0, 0, 1}};
    cout << "Test 2 - Expected: 3, Got: " << solution.findCircleNum(isConnected2) << endl;
    
    // Test case 3: One province (all connected)
    vector<vector<int>> isConnected3 = {{1, 1, 1}, 
                                         {1, 1, 1}, 
                                         {1, 1, 1}};
    cout << "Test 3 - Expected: 1, Got: " << solution.findCircleNum(isConnected3) << endl;

    return 0;
}