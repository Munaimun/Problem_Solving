#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string processStr(string s)
    {
        int n = s.size();
        string result;

        for (int i = 0; i < n; i++)
        {
            if (islower(s[i]))
            {
                result.push_back(s[i]);
            }
            else if (s[i] == '#')
            {
                result += result;
            }
            else if (s[i] == '%')
            {
                reverse(result.begin(), result.end());
            }
            else if (s[i] == '*')
            {
                if (!result.empty())
                    result.pop_back();
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.processStr("a#b%*") << endl;

    return 0;
}