#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

// https://leetcode.com/problems/course-schedule/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        vector<bool> visited(numCourses, 0);
        vector<bool> path(numCourses, 0);
        for (auto &it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && detectCycle(adj, visited, path, i))
            {
                return 0;
            }
        }
        return 1;
    }
    bool detectCycle(vector<int> adj[], vector<bool> &visited,
                     vector<bool> &path, int i)
    {
        visited[i] = 1;
        path[i] = 1;
        for (auto &it : adj[i])
        {
            if (path[it])
            {
                return 1;
            }
            if (!visited[it] && detectCycle(adj, visited, path, it))
            {
                return 1;
            }
        }
        path[i] = 0;
        return 0;
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