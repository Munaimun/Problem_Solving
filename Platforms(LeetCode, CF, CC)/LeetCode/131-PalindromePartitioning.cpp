/*
 * Time Complexity: O(N * 2^N)
 * - We have 2^N possible ways to partition the string
 * - For each partition, we need O(N) time to check if it's a palindrome
 * 
 * Space Complexity: O(N)
 * - Recursion depth can go up to N levels
 * - Each recursive call uses O(N) space for substring operations
 * - Not counting the space for storing all valid partitions in result
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    bool isPalindrome(string part)
    {
        int i = 0, j = part.size() - 1;
        
        // Compare characters from both ends moving towards center
        while(i < j) {
            if(part[i] != part[j]) return false;
            i++; 
            j--;
        }

        return true;
    }

    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans)
    {
        // Base case: if string is empty, we have a complete valid partition
        if (s.size() == 0)
        {
            ans.push_back(partitions);
            return;
        }

        // Try all possible prefixes of the current string
        for (int i = 0; i < s.size(); i++)
        {
            // Extract substring from start to position i (inclusive)
            string part = s.substr(0, i + 1);

            // Only proceed if the current part is a palindrome
            if (isPalindrome(part))
            {
                // Include this palindromic part in current partition
                partitions.push_back(part);
                
                // Recursively partition the remaining substring
                getAllParts(s.substr(i + 1), partitions, ans);
                
                // Backtrack: remove the current part to try other possibilities
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;        // Stores all valid partitions
        vector<string> partitions;         // Current partition being built
        
        // Start the recursive partitioning process
        getAllParts(s, partitions, ans);

        return ans;
    }
};

int main()
{
    Solution solver;
    string input = "aab";
    vector<vector<string>> result = solver.partition(input);

    // Print all valid partitions in required format
    for (const auto &partition : result)
    {
        cout << "[";
        for (size_t i = 0; i < partition.size(); ++i)
        {
            cout << "\"" << partition[i] << "\"";
            if (i + 1 < partition.size()) cout << ",";
        }
        cout << "]\n";
    }
    return 0;
}