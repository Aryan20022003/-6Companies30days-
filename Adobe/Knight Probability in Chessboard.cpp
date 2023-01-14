#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/knight-probability-in-chessboard/description/
class Solution
{
public:
    // #define int double
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(25, vector<vector<double>>(25, vector<double>(101, -1e9)));
        double ans = f(row, column, k, n, dp) / pow(8, k);
        return ans;
    }
    double f(double i, double j, double k, double n, vector<vector<vector<double>>> &dp)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            return 0;
        }
        if (k == 0)
        {
            return 1;
        }
        if (dp[i][j][k] != -1e9)
        {
            return dp[i][j][k];
        }
        double temparrx[] = {2, -2};
        double temparry[] = {1, -1};
        double temp = 0;
        for (auto &it : temparrx)
        {
            for (auto &ip : temparry)
            {
                temp += f(i + it, j + ip, k - 1, n, dp);
            }
        }
        for (auto &it : temparry)
        {
            for (auto &ip : temparrx)
            {
                temp += f(i + it, j + ip, k - 1, n, dp);
            }
        }
        return dp[i][j][k] = temp;
    }
};