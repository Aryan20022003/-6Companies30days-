// https://leetcode.com/problems/magical-string/description/
// pattern matching question
class Solution
{
public:
    int magicalString(int n)
    {
        vector<int> v = {1, 2, 2};
        int i = 2;
        while (v.size() < n)
        {
            if (v[i] == 1 && v[v.size() - 1] == 1)
            {
                v.push_back(2);
            }
            else if (v[i] == 1 && v[v.size() - 1] == 2)
            {
                v.push_back(1);
            }
            else if (v[v.size() - 1] == 2)
            {
                v.push_back(1);
                v.push_back(1);
            }
            else
            {
                v.push_back(2);
                v.push_back(2);
            }
            i++;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int it = v[i];
            if (it == 1)
                count++;
        }
        return count;
    }
};