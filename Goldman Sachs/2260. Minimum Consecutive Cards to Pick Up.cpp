#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 1e9;
        while (j < cards.size())
        {
            mp[cards[j]]++;
            if (mp[cards[j]] > 1)
            {
                while (mp[cards[j]] != 1)
                {
                    mp[cards[i]]--;
                    i++;
                }
                ans = min(ans, j - i + 1 + 1);
            }
            j++;
        }
        if (ans == 1e9)
        {
            return -1;
        }
        return ans;
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