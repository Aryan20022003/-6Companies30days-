// https://leetcode.com/problems/rotate-function/

// observation and must check solution aryan u have posted in discussion

#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int firstSum = 0;
        int sumBase = 0;
        int finalAnswer = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            firstSum += nums[i] * i;
            sumBase += nums[i];
        }
        finalAnswer = firstSum;
        int count = nums.size();
        for (int j = nums.size() - 1; j > 0; j--)
        {
            firstSum = firstSum + sumBase - count * nums[j];
            finalAnswer = max(finalAnswer, firstSum);
        }
        return finalAnswer;
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