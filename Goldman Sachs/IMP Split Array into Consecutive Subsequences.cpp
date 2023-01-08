// https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> demand, aval;
        for (auto &it : nums)
        {
            aval[it]++;
        }
        for (auto &it : nums)
        {
            if (aval[it] == 0)
            {
                continue;
            }
            else if (demand[it] != 0)
            {
                demand[it]--;
                aval[it]--;
                demand[it + 1]++;
            }
            else if (aval[it + 1] >= 1 && aval[it + 2] >= 1)
            {
                aval[it]--;
                aval[it + 1]--;
                aval[it + 2]--;
                demand[it + 3]++;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{

    return 0;
}