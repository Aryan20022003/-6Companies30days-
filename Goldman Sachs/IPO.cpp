#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

// concept is get best out of current avalaibale balance and is changing dynamically on the basis of the current available element
// some what similar to dakstra algo of graph.
// https://leetcode.com/problems/ipo/description/
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < profits.size(); i++)
        {
            vp.push_back({capital[i], profits[i]});
        }
        sort(vp.begin(), vp.end());
        priority_queue<int> pq;
        int i = 0;
        while (k != 0)
        {
            while (i < profits.size() && w >= vp[i].first)
            {
                pq.push(vp[i].second);
                i++;
            }
            if (pq.size() == 0)
            {
                break;
            }
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};