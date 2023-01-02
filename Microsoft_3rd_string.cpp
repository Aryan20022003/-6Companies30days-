// https://leetcode.com/problems/bulls-and-cows/
#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int count = 0;
        for (int i = 0; i < guess.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                count++;
            }
        }
        unordered_map<char, int> mp;
        for (auto &it : secret)
        {
            mp[it]++;
        }
        int alpha = 0;
        for (auto &it : guess)
        {
            if (mp[it] != 0)
            {
                alpha++;
                mp[it]--;
            }
        }
        string s = "";
        alpha -= count;
        // cout<<alpha<<"\n";

        return numToStr(count, alpha);
    }
    string numToStr(int count, int alpha)
    {
        string ans = "";
        if (count == 0)
        {
            ans += ('0');
        }
        else
        {
            string temp = "";
            while (count != 0)
            {
                temp += ('0' + count % 10);
                count /= 10;
            }
            reverse(temp.begin(), temp.end());
            ans = temp;
        }
        ans += 'A';
        if (alpha == 0)
        {
            ans += ('0');
        }
        else
        {
            string temp = "";
            while (alpha != 0)
            {
                temp += ('0' + alpha % 10);
                alpha /= 10;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        ans += 'B';
        return ans;
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
