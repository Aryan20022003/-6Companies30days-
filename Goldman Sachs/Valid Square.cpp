#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/valid-square/description/
class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> co = {p1, p2, p3, p4};
        map<int, int> mp;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == i)
                {
                    continue;
                }
                else
                {
                    int x = (co[i][0] - co[j][0]) * (co[i][0] - co[j][0]);
                    int y = (co[i][1] - co[j][1]) * (co[i][1] - co[j][1]);
                    if (x + y == 0)
                    {
                        return 0;
                    }
                    mp[x + y]++;
                }
            }
        }
        if (mp.size() != 2)
        {
            return 0;
        }
        else
        {
            int small = -1;
            int big = -1;
            for (auto &it : mp)
            {
                if (small == -1)
                {
                    small = it.first;
                    if (mp[2 * small] != 4 && it.second != 8)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /* Donot panic ARYAN */
    // solution is easy you just need to figure it out
    // try focusing on the inputs
    // if nothing comes to mind take a break of 2 mins
    ll test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}