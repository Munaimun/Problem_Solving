/*
Time Complexity: O(n + m)
    - n = size of nums1
    - m = size of nums2
    - We traverse both arrays once, and hash map operations are O(1) on average.

Space Complexity: O(k)
    - k = number of unique elements in nums1 (stored in the hash map)
    - Result vector uses at most min(n, m) space, but it's usually not counted unless specified.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        unordered_map<int, int> freq;
        for (int num : nums1)
            freq[num]++;

        vector<int> res;
        for (int num : nums2)
        {
            if (freq[num] > 0)
            {
                res.push_back(num);
                freq[num]--;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {4, 9, 9, 5};
    vector<int> n2 = {9, 4, 9, 8, 4};
    vector<int> result = s.intersect(n1, n2);

    for (auto i : result)
        cout << i << " ";

    cout << endl;

    return 0;
}
