/*
 * Function to find the unique intersection of two integer arrays.
 *
 * Time Complexity: O(n + m) on average
 *   - n = size of nums1
 *   - m = size of nums2
 *   - Inserting all elements of nums1 into an unordered_set takes O(n)
 *   - Checking and erasing elements in nums2 takes O(m) on average
 *
 * Space Complexity: O(n + k)
 *   - n for storing elements of nums1 in the unordered_set
 *   - k for storing the intersection result (number of unique intersecting elements)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // Step 1: Insert all elements of nums1 into an unordered_set for O(1) average lookup
        unordered_set<int> s(nums1.begin(), nums1.end());

        vector<int> res;
        // Step 2: Iterate through nums2, check if element exists in set
        for (int i = 0; i < nums2.size(); i++)
        {
            if (s.find(nums2[i]) != s.end())
            {
                res.push_back(nums2[i]); // Add element to result vector
                s.erase(nums2[i]);       // Remove element from set to avoid duplicates in result
            }
        }

        // Step 3: Return the unique intersection vector
        return res;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution obj;
    vector<int> result = obj.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
