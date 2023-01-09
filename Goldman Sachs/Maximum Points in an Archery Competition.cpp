#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

// https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/
// simple Choose not Choose.
class Solution
{
public:
    vector<int> ans; // will save the final answer.
    int scoreCount = 0;
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        vector<int> temp(12, 0);
        f(numArrows, temp, 0, aliceArrows);
        return ans;
    }
    void f(int arrows, vector<int> &v, int i, vector<int> &ref)
    {
        if (arrows == 0 || i == 12)
        {
            if (i == 12 && arrows != 0)
            {
                // edge case when excess of arrows are give.
                v[11] += arrows;
            }
            int temp = cal(v, ref);
            if (temp > scoreCount)
            {
                scoreCount = temp;
                ans = v;
            }
            return;
        }
        // not choose the number
        f(arrows, v, i + 1, ref);

        v[i] = 0; // incase we have handled edge case then just undo that step

        // choose the number if we have enough arrows
        if (ref[i] < arrows)
        {
            v[i] = ref[i] + 1;
            f(arrows - ref[i] - 1, v, i + 1, ref);
            v[i] = 0;
        }
    }
    int cal(vector<int> &v, vector<int> &ref)
    {
        int temp = 0;
        for (int i = 0; i < 12; i++)
        {
            if (v[i] > ref[i])
            {
                temp += i;
            }
        }
        return temp;
    }
};