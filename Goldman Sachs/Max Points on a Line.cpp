// https://leetcode.com/problems/max-points-on-a-line/description/
#define ll long long int
class Solution
{
public:
    // time O(N3) space O(1)
    int maxPoints(vector<vector<int>> &points)
    {
        return f(points);
        if (points.size() <= 2)
        {
            return points.size();
        }
        ll ans = 0;
        for (ll i = 0; i < points.size(); i++)
        {
            for (ll j = i + 1; j < points.size(); j++)
            {
                ll x1 = points[i][0] - points[j][0];
                ll y1 = points[i][1] - points[j][1];

                ll sign1 = 1;
                if ((x1 < 0 && y1 > 0) || (x1 > 0 && y1 < 0))
                {
                    sign1 = -1;
                }

                ll temp = __gcd(abs(x1), abs(y1));
                if (y1 != 0 && x1 != 0)
                {
                    x1 = abs(x1) / temp;
                    y1 = abs(y1) / temp;
                }
                ll count = 1;
                for (ll k = 0; k < points.size(); k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    ll x2 = points[i][0] - points[k][0];
                    ll y2 = points[i][1] - points[k][1];

                    ll sign2 = 1;
                    if ((x2 < 0 && y2 > 0) || (x2 > 0 && y2 < 0))
                    {
                        sign2 = -1;
                    }

                    ll temp = __gcd(abs(x2), abs(y2));
                    if (y1 != 0 && x1 != 0)
                    {
                        x2 = abs(x2) / temp;
                        y2 = abs(y2) / temp;
                    }
                    // cout<<x2<<" "<<y2<<".....\n";
                    if (x1 == 0 && x2 == 0)
                    {
                        count++;
                    }
                    else if (y2 == 0 && y1 == 0)
                    {
                        count++;
                    }
                    else if (y1 == y2 && x1 == x2 && sign1 == sign2)
                    {
                        count++;
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
    // time optiome solution O(N2) space O(N);
    int f(vector<vector<int>> &v)
    {
        if (v.size() <= 2)
        {
            return v.size();
        }

        int ans = 1;
        for (int i = 0; i < v.size(); i++)
        {
            // int temp=1;
            unordered_map<double, int> mp;
            for (int j = i + 1; j < v.size(); j++)
            {
                ll x1 = v[i][0] - v[j][0];
                ll y1 = v[i][1] - v[j][1];
                if (x1 == 0)
                {
                    mp[-90]++;
                }
                else
                {
                    double temp = (double)y1 / (double)x1;
                    mp[temp]++;
                }
            }
            for (auto &it : mp)
            {
                ans = max(ans, it.second);
            }
        }
        return ans + 1;
    }
};