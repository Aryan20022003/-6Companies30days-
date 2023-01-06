#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/
class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        map<int, int> m1; // to store the count the nums and to sort
        for (auto it : nums)
        {
            m1[it]++;
        }

        int ans = numsDivide[0];

        for (auto it : numsDivide)
        {
            ans = __gcd(ans, it);
        }

        int count = 0;

        for (auto it : m1)
        {
            if (ans % it.first == 0)
            {
                return count;
            }
            else
            {
                count += it.second;
            }
        }
        return -1;
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