// https://leetcode.com/problems/number-of-boomerangs/
// https://leetcode.com/problems/number-of-boomerangs/solutions/3020102/easy-hash-map-similar-to-number-of-lines-question-o-n2/?orderBy=most_votes
#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> mp;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    int dis = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                    mp[dis]++;
                }
            }
            for (auto &it : mp)
            {
                ans += it.second * (it.second - 1);
            }
        }
        return ans;
    }
};