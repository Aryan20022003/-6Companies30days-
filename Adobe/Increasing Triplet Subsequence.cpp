#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

// https://leetcode.com/problems/increasing-triplet-subsequence/description/
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<long long int> prev(3, 1e13);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < prev[0])
            {
                prev[0] = nums[i];
            }
            else if (nums[i] < prev[1] && prev[0] < nums[i])
            {
                prev[1] = nums[i];
            }
            else if (nums[i] < prev[2] && prev[1] < nums[i])
            {
                return 1;
            }
        }
        return 0;
    }
};