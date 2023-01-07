#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        vector<int> v;
        for (int i = 0; i < nums1.size(); i++)
        {
            v.push_back(nums1[i] - nums2[i]);
        }
        return f(v, 0, nums1.size() - 1, diff);
    }
    long long int f(vector<int> &v, int start, int end, int diff)
    {
        if (start >= end)
        {
            return 0;
        }
        long long int mid = (start + end) >> 1;
        long long int ans = f(v, start, mid, diff) + f(v, mid + 1, end, diff);

        // sort1(v,start,mid);
        // sort1(v,mid+1,end);
        // sort(v.begin()+start,v.begin()+mid+1);
        // sort(v.begin()+mid+1,v.begin()+end+1);

        for (int i = mid + 1; i <= end; i++)
        {
            ans += upper_bound(v.begin() + start, v.begin() + mid + 1, v[i] + diff) - v.begin() - start;
        }
        sort1(v, start, end);

        return ans;
    }
    // gap method to merge two sorted array
    void sort1(vector<int> &v, int start, int end)
    {

        int temp = end - start + 1;
        while (temp != 1)
        {
            temp = (temp + 1) / 2;
            int i = start, j = temp + start;
            // cout<<i<<" "<<j<<" "<<temp<<"\n";
            while (j <= end)
            {
                if (v[i] > v[j])
                {
                    swap(v[i], v[j]);
                }
                i++;
                j++;
            }
        }
        return;
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