#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
ll bs_sqrt(ll x)
{
    ll left = 0, right = 2000000123;
    while (right > left)
    {
        ll mid = (left + right) / 2;
        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}
// https://leetcode.com/problems/factorial-trailing-zeroes/description/
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int temp = n / 5;
        temp *= 5;
        return f(temp);
    }
    int f(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        return n / 5 + f(n / 5);
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