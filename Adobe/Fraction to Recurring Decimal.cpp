#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;
// https://leetcode.com/problems/fraction-to-recurring-decimal/
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        unordered_map<long long int, long long int> mp;
        bool negative = 0;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
        {
            negative = 1;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long long int temp = numerator / denominator;
        string nondec = "";
        if (temp == 0)
        {
            nondec += "0";
        }
        else
        {
            nondec += convertTostring(temp);
        }
        if (numerator % denominator == 0)
        {
            if (negative)
            {
                return "-" + nondec;
            }
            return nondec;
        }
        string dec = ".";
        long long int num = (numerator % denominator);
        long long int i = 1;
        bool flag = 0;
        while (true)
        {
            if (mp[num] != 0)
            {
                flag = 1;
                break;
            }
            else if (num == 0)
            {
                break;
            }
            mp[num] = i;
            i++;
            long long int numc = (num * 10) / denominator;
            if (numc == 0)
            {
                dec += "0";
            }
            else
            {
                dec += convertTostring(numc);
            }
            num = (num * 10) % denominator;
        }
        if (flag)
        {
            long long int index = mp[num];
            string finaldec = "";
            for (long long int i = 0; i < dec.size(); i++)
            {
                if (i == index)
                {
                    finaldec += "(";
                }
                finaldec += dec[i];
            }
            finaldec += ")";
            dec = finaldec;
        }
        if (negative)
        {
            return "-" + nondec + dec;
        }
        return nondec + dec;
    }
    string convertTostring(long long int num)
    {
        string temps = "";
        long long int flag = 0;
        while (num != 0)
        {
            temps += ('0' + num % 10);
            num /= 10;
        }
        reverse(temps.begin(), temps.end());
        return temps;
    }
};