#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int f = 0, ans;

        // Iterate through the array to find the majority element
        // using Boyer-Moore Voting Algorithm
        for (int i = 0; i < nums.size(); i++)
        {
            // If the counter is zero, set the current element as the potential majority
            if (f == 0)
                ans = nums[i];

            // If current element matches the candidate, increment the counter
            if (ans == nums[i])
                f++;
            else
                f--; // Else, decrement the counter
        }

        // Return the element that is the majority as per the problem guarantee
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> vec = {1, 2, 1, 1, 2};

    int ans = sol.majorityElement(vec);

    cout << ans << "\n";
}