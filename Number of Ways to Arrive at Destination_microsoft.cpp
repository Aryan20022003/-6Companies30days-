// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
#define ll long long int
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<ll> dis(n, LONG_MAX);
        vector<ll> ways(n, 0);
        ll M = (ll)(1e9 + 7);
        vector<pair<ll, ll>> adj[n];
        for (auto &it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        dis[0] = 0;
        ways[0] = 1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        // pair={time,node};
        pq.push({0, 0});
        while (pq.size() != 0)
        {
            auto temp = pq.top();
            pq.pop();
            ll dist = temp.first;
            ll parent = temp.second;
            ll noWays = (ways[parent]) % M;
            for (auto &it : adj[parent])
            {
                ll child = it.first;
                ll time = it.second;
                if (dis[child] > time + dist)
                {
                    ways[child] = noWays;
                    dis[child] = time + dist;
                    pq.push({dis[child], child});
                }
                else if (dis[child] == time + dist)
                {
                    ways[child] = (ways[child] + noWays) % M;
                }
            }
        }
        return (ways[n - 1]) % M;
    }
};