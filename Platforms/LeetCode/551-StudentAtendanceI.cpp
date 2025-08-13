// Time Complexity: O(n), where n is the length of the string `s`
// Space Complexity: O(1), constant space used for counters

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int abs = 0, late = 0; // Counters for absences and consecutive lates
        bool flag = true;      // Assume the student is eligible unless rules are violated

        for (auto c : s)
        {
            if (c == 'A')
            {
                abs++;        // Count absence
                if (abs >= 2) // More than 1 absence invalidates the eligibility
                    flag = false;

                late = 0; // Reset late streak since it's broken by an 'A'
            }
            else if (c == 'L')
            {
                late++;        // Count consecutive lates
                if (late >= 3) // 3 or more consecutive lates are not allowed
                    flag = false;
            }
            else
            {
                late = 0; // Reset streak if character is 'P' or anything else
            }
        }

        return flag; // Return whether student is eligible
    }
};

int main()
{
    Solution s;
    cout << s.checkRecord("PPALLL") << endl;

    return 0;
}
