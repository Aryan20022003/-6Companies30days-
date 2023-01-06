#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> copy = nums;
        sort(nums.begin(), nums.end());
        int head = -1, count = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] != copy[i])
            {
                if (head == -1)
                {
                    head = i;
                }
                count = (i - head + 1);
            }
            i++;
        }
        return count;
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