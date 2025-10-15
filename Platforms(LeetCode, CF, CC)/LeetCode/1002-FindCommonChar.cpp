#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        // Step 1: Use 26-sized vector to count chars from a-z
        vector<int> mainMap(26, INT_MAX); // Use INT_MAX here to take min later

        for (int i = 0; i < words.size(); i++)
        {
            vector<int> temp(26, 0); // Frequency count of current word

            for (char c : words[i])
            {
                temp[c - 'a']++;
            }

            // Step 2: Update mainMap with min frequency
            for (int j = 0; j < 26; j++)
            {
                mainMap[j] = min(mainMap[j], temp[j]);
            }
        }

        // Step 3: Build result from mainMap
        vector<string> res;
        for (int i = 0; i < 26; i++)
        {
            while (mainMap[i]-- > 0)
            {
                res.push_back(string(1, 'a' + i));
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"bella", "label", "roller"};

    vector<string> result = sol.commonChars(words);

    for (auto &ch : result)
    {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}
