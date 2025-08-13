class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0, j = 0, n = s.size();
        while (j <= n)
        {
            if (j == n || s[j] == ' ')
            {
                reverse(s.begin() + i, s.begin() + j);
                j++;
                i = j;
            }
            else
                j++;
        }
        return s;
    }
};