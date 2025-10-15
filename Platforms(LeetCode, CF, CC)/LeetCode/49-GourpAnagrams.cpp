/**
 * Group Anagrams
 * Time Complexity: O(N * M), where N is the number of strings and M is the maximum length of a string.
 *   - For each string: counting letters = O(M), generating key = O(26)
 *   - Inserting into map = average O(1) per insert
 * Space Complexity: O(N * M)
 *   - Map stores all strings grouped in vectors
 *   - Count array is constant size (26)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Hash map to group anagrams using letter frequency signature as key
        unordered_map<string, vector<string>> ans;

        for (auto &s : strs)
        {
            // Count frequency of each character (a-z) in current string
            array<int, 26> count = {0};
            for (char c : s)
                count[c - 'a']++;

            // Generate a unique key from the frequency count
            string key;
            for (int num : count)
                key += to_string(num) + "#"; // '#' separates counts to avoid ambiguity

            // Group the string under the generated key
            ans[key].push_back(s);
        }

        // Extract all anagram groups from the hash map into the result vector
        vector<vector<string>> res;
        for (auto &entry : ans)
            res.push_back(move(entry.second)); // move to avoid deep copy and improve performance

        return res;
    }
};

// Utility function to print the grouped anagrams
void printGroupedAnagrams(const vector<vector<string>> &groups)
{
    for (const auto &group : groups)
    {
        cout << "[ ";
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    Solution sol;

    // Sample input
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Group anagrams
    vector<vector<string>> result = sol.groupAnagrams(input);

    // Print result
    cout << "Grouped Anagrams:" << endl;
    printGroupedAnagrams(result);

    return 0;
}
