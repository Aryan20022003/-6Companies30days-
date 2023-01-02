// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// observation and must check solution aryan u have posted in discussion

#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        unordered_map<char, int> mp;
        int count = 0;
        int i = 0, j = 0;
        while (i <= s.size())
        {
            mp[s[i]]++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
            {
                count += s.size() - i;
                mp[s[j]]--;
                j++;
            }
            i++;
        }
        return count;
    }
};
int main()
{
    /* Donot panic ARYAN */
    // solution is easy you just need to figure it out
    // try focusing on the inputs
    // if nothing comes to mind take a break of 2 mins
    return 0;
}