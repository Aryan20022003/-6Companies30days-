#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/
class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        ll M = 1e9 + 7;
        unordered_map<ll, ll> mp;
        for (auto it : nums)
        {
            mp[it - rev(it)]++;
        }
        ll ans = 0;
        for (auto &it : mp)
        {
            ans += (it.second * (it.second - 1) / 2) % M;
        }
        return ans % M;
    }
    ll rev(ll num)
    {
        int temp = 0;
        while (num != 0)
        {
            temp = temp * 10 + num % 10;
            num /= 10;
        }
        return temp;
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