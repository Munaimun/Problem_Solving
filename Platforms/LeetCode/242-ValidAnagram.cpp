#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> myMap;

        // Count characters in s
        for (int i = 0; i < s.size(); i++)
        {
            myMap[s[i]]++;
        }

        // Subtract counts using characters from t
        for (int i = 0; i < t.size(); i++)
        {
            myMap[t[i]]--;
        }

        // Check if all counts are 0
        for (auto it : myMap)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    cout << boolalpha << sol.isAnagram("fahad", "dahaf") << endl;
}
