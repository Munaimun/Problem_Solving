/*
Problem: LeetCode 841 - Keys and Rooms
Algorithm: DFS (Depth-First Search) for graph traversal

Approach:
- Model the problem as a directed graph where each room is a node
- An edge exists from room i to room j if room i contains a key to room j
- Start from room 0 (which is unlocked) and perform DFS
- Use DFS to visit all rooms that are reachable using available keys
- After DFS, check if all rooms have been visited

Time Complexity: O(n + k)
- n = number of rooms
- k = total number of keys across all rooms
- We visit each room at most once: O(n)
- We process each key at most once: O(k)
- Total: O(n + k)

Space Complexity: O(n)
- isVisited array: O(n)
- Recursion stack depth in worst case (all rooms in a chain): O(n)
- Total: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // DFS helper function to visit all reachable rooms from current room
    void dsf(int u, vector<bool> &isVisited, vector<vector<int>> &rooms)
    {
        // Mark the current room as visited
        isVisited[u] = true;

        // Iterate through all keys in the current room
        for (auto v : rooms[u])
        {
            // If the room corresponding to this key hasn't been visited yet
            if (!isVisited[v])
            {
                // Recursively visit that room
                dsf(v, isVisited, rooms);
            }
        }
    }

    // Main function to check if all rooms can be visited
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size(); // Total number of rooms
        vector<bool> isVisited(n, false); // Track visited rooms (initially all unvisited)

        // Start DFS from room 0 (which is initially unlocked)
        dsf(0, isVisited, rooms);

        // Check if there is any room that remains unvisited
        for (int i = 0; i < n; i++)
        {
            // If any room is not visited, we cannot visit all rooms
            if (isVisited[i] == false)
                return false;
        }

        // All rooms have been visited
        return true;
    }
};

int main()
{
    Solution solution;
    
    // Test case 1: Can visit all rooms
    // Room 0 has key to room 1, room 1 has keys to rooms 2 and 3
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    cout << "Test 1 - Expected: 1 (true), Got: " << solution.canVisitAllRooms(rooms1) << endl;
    
    // Test case 2: Cannot visit all rooms
    // Room 0 has key to room 1, but no way to reach room 2 or 3
    vector<vector<int>> rooms2 = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout << "Test 2 - Expected: 0 (false), Got: " << solution.canVisitAllRooms(rooms2) << endl;
    
    // Test case 3: Single room (always visitable)
    vector<vector<int>> rooms3 = {{}};
    cout << "Test 3 - Expected: 1 (true), Got: " << solution.canVisitAllRooms(rooms3) << endl;

    return 0;
}