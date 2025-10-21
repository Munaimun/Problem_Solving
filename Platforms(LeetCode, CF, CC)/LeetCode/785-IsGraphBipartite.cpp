// Problem Statement:
// You are given an undirected graph represented as an adjacency list (vector<vector<int>>).
// Determine if the graph is **bipartite**, meaning you can color each node using two colors
// such that no two adjacent nodes share the same color.
//
// A bipartite graph contains NO ODD-LENGTH CYCLES.
//
// Time Complexity:  O(V + E)   → BFS traversal over all nodes & edges
// Space Complexity: O(V)       → to store the color array + BFS queue

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);  // 0 = uncolored, 1 and 2 are two different colors

        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)  // If this node is not colored yet, start a BFS from here
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;   // Assign first color

                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();

                    int nextColor = (color[u] == 1) ? 2 : 1;

                    for (auto v : graph[u])   // Check all neighbors
                    {
                        if (color[v] == 0)    // If neighbor is not colored → color it
                        {
                            q.push(v);
                            color[v] = nextColor;
                        }
                        else if (color[v] == color[u]) // Adjacent same color → NOT bipartite
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true; // If no conflict found → graph is bipartite
    }
};

int main()
{
    Solution s;
    
    // Example: Graph with edges: 0-1, 1-2, 2-3 → Bipartite ✅
    vector<vector<int>> graph = {{1}, {0, 2}, {1, 3}, {2}};
    
    cout << (s.isBipartite(graph) ? "Graph is Bipartite" : "Graph is NOT Bipartite") << endl;

    return 0;
}
