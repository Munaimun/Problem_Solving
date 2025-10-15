// Time Complexity: O(n)
// - n = number of words or characters in the pattern (since both must be equal in size)
// - Each word and character is processed once
// - unordered_map operations are O(1) average-case

// Space Complexity: O(n)
// - Space used by the 'words' vector: O(n)
// - Space used by two unordered_maps: O(n) total in worst case

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        vector<string> words; // to store all the word from s
        istringstream iss(s); // special func to read all the word without space
        string word;
        // stores all the words in vector words
        while (iss >> word)
            words.push_back(word);

        // edge case: if the pattern and s are not same in size, return false
        if (pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.size(); i++)
        {
            char ch = pattern[i];
            string w = words[i];

            // if ch is already mapped
            if (m1.count(ch))
            {
                // if the char and word don’t match, return false
                if (m1[ch] != w)
                    return false;
            }
            else
            {
                // store the key-value when it's not mapped
                m1[ch] = w;
            }

            // if w is already mapped
            if (m2.count(w))
            {
                if (m2[w] != ch)
                    return false; // return false if key-value doesn't match
            }
            else
            {
                m2[w] = ch;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << boolalpha << sol.wordPattern(pattern, s) << endl;
    return 0;
}
