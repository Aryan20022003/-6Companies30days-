// https://leetcode.com/problems/longest-happy-prefix/description/
class Solution
{
public:
    string longestPrefix(string s)
    {
        vector<int> LPS(s.size(), 0);
        int i = 1, len = 0;
        while (i < s.size())
        {
            if (s[len] == s[i])
            {
                len++;
                LPS[i] = len;
                i++;
            }
            else
            {
                if (len > 0)
                {
                    len = LPS[len - 1];
                }
                else
                {
                    LPS[i] = len;
                    i++;
                }
            }
        }
        return s.substr(0, LPS[s.size() - 1]);
    }
};