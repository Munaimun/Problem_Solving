// Problem: Course Schedule II (LeetCode 210)
// Given numCourses and prerequisites, return a valid order of courses
// so that all prerequisites are satisfied. If impossible, return empty array.
// Approach: BFS (Kahn's Algorithm) using in-degree array.

/*
Time Complexity: 
    - O(V + E), where V = numCourses, E = number of prerequisites
      Each course is processed once, and each edge is visited once.

Space Complexity:
    - O(V + E)
      For adjacency list + in-degree array + queue + answer vector.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        // Step 1: Build adjacency list and compute in-degree of each course
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for (auto edge : prerequisites)
        {
            int u = edge[1]; // prerequisite course
            int v = edge[0]; // course that depends on u

            adj[u].push_back(v); // add edge u -> v
            inDegree[v]++;       // increment in-degree of v
        }

        // Step 2: Initialize queue with courses having in-degree 0
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i); // courses with no prerequisites
        }

        // Step 3: BFS to determine course order
        vector<int> ans; // stores the final course order

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            ans.push_back(u); // take course u

            // Reduce in-degree of neighbors and add to queue if they become 0
            for (auto v : adj[u])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        // Step 4: Check if all courses are processed
        if (ans.size() == n)
            return ans; // valid order
        else
            return {};  // cycle detected, impossible to finish
    }
};

int main()
{
    // Example input
    int n = 4;
    vector<vector<int>> prerequisites = {
        {1, 0}, // To take 1, must finish 0
        {2, 0}, // To take 2, must finish 0
        {3, 1}, // To take 3, must finish 1
        {3, 2}  // To take 3, must finish 2
    };

    Solution s;
    vector<int> res = s.findOrder(n, prerequisites);

    // Print the result
    if (res.empty())
        cout << "Impossible to finish all courses" << endl;
    else
    {
        cout << "Course order: ";
        for (auto i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}