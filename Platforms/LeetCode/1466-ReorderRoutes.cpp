/*
Problem: LeetCode 1466 - Reorder Routes to Make All Paths Lead to the City Zero
Algorithm: DFS (Depth-First Search) on bidirectional graph with edge direction tracking

Approach:
- Original graph has directed edges showing roads from city A to city B
- We need all roads to lead TO city 0, so we need to count how many roads point AWAY from 0
- Build a bidirectional graph where:
  * Original edges (u → v) have weight 1 (need to be reversed)
  * Reverse edges (v → u) have weight 0 (already correct direction)
- Perform DFS from city 0 treating the graph as undirected
- Sum up weights of edges traversed in DFS direction
- The weight sum = number of edges that need to be reversed

Example: connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
- Edge 0→1: needs reversal (going away from 0)
- Edge 1→3: needs reversal (going away from path to 0)
- Edge 2→3: already correct (3 can reach towards 0)
- Total reversals needed: 3

Time Complexity: O(n)
- Building adjacency list: O(n) since we have n-1 edges in a tree
- DFS visits each node exactly once: O(n)
- Total: O(n)

Space Complexity: O(n)
- Adjacency list storage: O(n) for n-1 edges stored bidirectionally
- Recursion stack depth: O(n) in worst case (skewed tree)
- Total: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS to traverse the tree and count edges that need reversal
    void dfs(int u, int par, int &cnt, vector<vector<pair<int, int>>> &adj) {
        // Explore all neighbors of current node
        for (auto e : adj[u]) {
            int v = e.first;   // Neighbor node
            int w = e.second;  // Edge weight (1 = needs reversal, 0 = correct direction)

            // Avoid going back to parent (prevent infinite loop)
            if (par != v) {
                // Add weight to count (1 if edge needs reversal, 0 otherwise)
                cnt += w;
                // Recursively visit the neighbor, marking current node as parent
                dfs(v, u, cnt, adj);
            }
        }
    }

    // Main function to find minimum number of edge reversals needed
    int minReorder(int n, vector<vector<int>>& connections) {
        // Build bidirectional adjacency list with weights
        vector<vector<pair<int, int>>> adj(n);

        // Process each directed edge in original connections
        for (auto e : connections) {
            int u = e[0];  // Source city
            int v = e[1];  // Destination city

            // Add original edge direction with weight 1 (needs reversal if traversed)
            adj[u].push_back({v, 1});
            
            // Add reverse edge direction with weight 0 (correct direction if traversed)
            adj[v].push_back({u, 0});
        }

        // Counter for number of edges that need to be reversed
        int cnt = 0;
        
        // Start DFS from city 0 with no parent (-1)
        dfs(0, -1, cnt, adj);

        // Return total number of reversals needed
        return cnt;
    }
};


int main() {
    Solution solution;
    
    // Test case 1: Need to reverse 3 edges
    vector<vector<int>> connections1 = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    int n1 = 6;
    cout << "Test 1 - Expected: 3, Got: " << solution.minReorder(n1, connections1) << endl;
    
    // Test case 2: Need to reverse 2 edges
    vector<vector<int>> connections2 = {{1,0},{1,2},{3,2},{3,4}};
    int n2 = 5;
    cout << "Test 2 - Expected: 2, Got: " << solution.minReorder(n2, connections2) << endl;
    

    return 0;
}