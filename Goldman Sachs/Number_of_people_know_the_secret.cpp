#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/
class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int M = 1e9 + 7;
        vector<int> ans(n + 1, 0);
        ans[1] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + delay; j < i + forget && j <= n; j++)
            {
                ans[j] = (ans[j] + ans[i]) % M;
            }
        }
        int finalAnswer = 0;
        for (int i = n; i >= 0 && i > n - forget; i--)
        {
            finalAnswer += ans[i];
            finalAnswer %= M;
        }
        return finalAnswer;
    }
};