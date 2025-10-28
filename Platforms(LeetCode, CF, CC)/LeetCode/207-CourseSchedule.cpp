/**
 * Problem: Check if all courses can be finished given prerequisites (LeetCode 207 - Course Schedule)
 * Approach: Use Kahn's Algorithm (BFS Topological Sort) to detect cycles in directed graph
 */

// Time Complexity (TC):
// O(V + E)
// - V = number of courses (nodes)
// - E = number of prerequisites (edges)
// - We visit each course once and process each edge once in the BFS loop.
//
// Space Complexity (SC):
// O(V + E)
// - adj list stores all edges → O(E)
// - indegree array stores V integers → O(V)
// - queue can hold up to V nodes → O(V)
// - ans vector stores topological order → O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        // Step 1: Build adjacency list and indegree array
        vector<vector<int>> adj(n); // adj[u] = list of courses dependent on course u
        vector<int> inDegree(n, 0); // inDegree[v] = number of prerequisites for course v

        for (auto edge : prerequisites)
        {
            int u = edge[1]; // prerequisite course
            int v = edge[0]; // course to take after u

            adj[u].push_back(v); // u -> v edge
            inDegree[v]++;       // v has one more prerequisite
        }

        // Step 2: Initialize queue with courses having 0 indegree (no prerequisites)
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i); // ready to take
        }

        // Step 3: Process courses in BFS manner
        vector<int> ans; // stores topological order of courses
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u); // course u can be taken

            // Reduce indegree of all dependent courses
            for (auto v : adj[u])
            {
                inDegree[v]--;        // one prerequisite done
                if (inDegree[v] == 0) // if no more prerequisites left
                    q.push(v);        // course ready to take
            }
        }

        // Step 4: If all courses are processed, no cycle exists
        return (ans.size() == n); // true if all courses can be finished
    }
};

int main()
{
    int n = 2;
    vector<vector<int>> prerequisites = {
        {1, 0}, // To take course 1, must first take 0
        // {0, 1}, // Uncommenting this would create a cycle
    };

    Solution s;
    cout << s.canFinish(n, prerequisites) << endl; // Output: 1 (true)

    return 0;
}