#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

// https://leetcode.com/problems/most-profitable-path-in-a-tree/description/
class Solution
{
public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        vector<int> stepsByBobToReach(amount.size(), 1e9);
        vector<int> adj[amount.size()];
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        walkOfBob(adj, stepsByBobToReach, bob, 0, bob);
        return MaximumpointByAlice(amount, stepsByBobToReach, adj, 0, 0, 0);
    }
    bool walkOfBob(vector<int> adj[], vector<int> &reached, int bob, int steps, int parent)
    {
        if (bob == 0)
        {
            reached[bob] = steps;
            return 1;
        }
        reached[bob] = steps;
        for (auto &it : adj[bob])
        {
            if (it != parent)
            {
                if (walkOfBob(adj, reached, it, steps + 1, bob))
                {
                    return 1;
                }
            }
        }
        reached[bob] = 1e9; // back tracking step as it does not lead the walk to zero/root;
        return 0;
    }
    int MaximumpointByAlice(vector<int> &amount, vector<int> &stepsB, vector<int> adj[], int node, int step, int parent)
    {
        int ans = 0;
        if (step < stepsB[node])
        {
            ans += amount[node];
        }
        else if (step == stepsB[node])
        {
            ans += amount[node] / 2;
        }
        int temp = -1e9;
        for (auto &it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            temp = max(temp, MaximumpointByAlice(amount, stepsB, adj, it, step + 1, node));
        }
        return temp == -1e9 ? ans : ans + temp;
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