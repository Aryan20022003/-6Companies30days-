// https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        long long int ans = 0;
        for (auto &it : tokens)
        {
            if (it != "+" && it != "-" && it != "*" && it != "/")
            {
                st.push(getint(it));
            }
            else
            {
                long long int a1 = st.top();
                st.pop();
                long long int a2 = st.top();
                st.pop();
                if (it == "+")
                {
                    ans = a2 + a1;
                }
                else if (it == "-")
                {
                    ans = a2 - a1;
                }
                else if (it == "*")
                {
                    ans = a2 * a1;
                }
                else
                {
                    ans = a2 / a1;
                }
                st.push(ans);
            }
        }
        return st.top();
    }
    long long getint(string s)
    {
        long long int temp = 0;

        if (s[0] == '-')
        {
            temp = getint(s.substr(1));
            return -temp;
        }
        else
        {
            for (auto &it : s)
            {
                // cout<<it<<"\n";
                temp = temp * 10 + (it - '0');
            }
            cout << temp << "\n";
        }
        return temp;
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