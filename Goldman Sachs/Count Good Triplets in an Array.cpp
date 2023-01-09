#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
// https://www.youtube.com/watch?v=sHXYxteLoDM
// awesom discussion by ram ram coders
// https://leetcode.com/problems/count-good-triplets-in-an-array/description/
//  in the case when we need to find the triplet then focus of middle element
// as when we choose middle elemnet rest of the elemnet can we choosen on the go, as left and right element can be choosen at max in order of N
// Declaring ordered_set
typedef tree<long long, null_type, less<long long>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<long long, long long> mp;
        ordered_set left, right;
        for (long long i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = i;
        }
        vector<long long> left1(nums2.size()), right1(nums2.size());
        left.insert(mp[nums1[0]]);
        right.insert(-mp[nums1[nums1.size() - 1]]);
        for (long long i = 1; i < nums1.size() - 1; i++)
        {
            left1[i] = left.order_of_key(mp[nums1[i]]);
            left.insert(mp[nums1[i]]);
        }
        for (long long i = nums1.size() - 2; i > 0; i--)
        {
            right1[i] = right.order_of_key(-mp[nums1[i]]);
            right.insert(-mp[nums1[i]]);
        }

        long long ans = 0;
        for (long long i = 1; i < nums2.size() - 1; i++)
        {
            ans += left1[i] * right1[i];
        }
        return ans;
    }
};