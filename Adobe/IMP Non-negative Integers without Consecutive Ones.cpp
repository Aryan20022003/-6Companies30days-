#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
class Solution
{
public:
    int findIntegers(int n)
    {
        vector<int> fibo(32, 0);
        fibo[0] = 1;
        fibo[1] = 2;
        for (int i = 2; i < 32; i++)
        {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        int ans = 0, i = 31;
        bool prev_1 = 0;
        while (i >= 0)
        {
            if (n & (1 << i))
            {
                ans += fibo[i];
                if (prev_1)
                    return ans;
                prev_1 = 1;
            }
            else
            {
                prev_1 = 0;
            }
            i--;
        }
        return ans + 1;
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