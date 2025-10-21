// Problem Statement:
// Given an undirected graph (as adjacency list), determine if it is BIPARTITE.
// A graph is bipartite if we can color its nodes using 2 colors such that
// no two ADJACENT nodes have the SAME color.
//
// We use DFS to color each connected component.
// If at any point adjacent nodes have same color → NOT bipartite.
//
// Time Complexity:  O(V + E)
// Space Complexity: O(V)    (for color[] + recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int u, int nextClr, bool &isBipartite, vector<int> &color, vector<vector<int>> &graph)
    {
        color[u] = nextClr;  // Color current node

        for (auto v : graph[u])  // Traverse all neighbors
        {
            if (color[v] == 0)   // If not colored → color with opposite color
                dfs(v, (nextClr == 1) ? 2 : 1, isBipartite, color, graph);
            else if (color[v] == color[u]) // If neighbor has same color → NOT bipartite
                isBipartite = false;
        }
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);     // 0 → uncolored, 1 and 2 are the two colors
        bool isBipartite = true;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)       // If this node not colored yet → start DFS
                dfs(i, 1, isBipartite, color, graph);
        }

        return isBipartite;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> graph1 = {{1,3},{0,2},{1,3},{0,2}};
    cout << (s.isBipartite(graph1) ? "Graph is Bipartite" : "Graph is NOT Bipartite") << endl;

    return 0;
}