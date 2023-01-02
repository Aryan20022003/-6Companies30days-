// https://leetcode.com/problems/largest-divisible-subset/description/

#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // even one can divide them self therfore each one is parent of them self
        // and minimum divisor is 1
        vector<int> parent(nums.size()), divc(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            parent[i] = i;
        }

        int ansbegins = 0; // atleast one will be answer
        int maximumLongestCount = 1;

        // if b%a==0 and no of divior of a + 1(a itself)>no of divisor of b mean b is paret of a;
        // now as we move forward we just have to check if some one is diving any number and count is greater than his current count then we include that number

        // a b c d e f
        // we are at d now we are sure divisor of d is less than d so we will check of divisor which can contribute maximum number of divisore of d.
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0 && divc[j] + 1 > divc[i])
                {
                    divc[i] = divc[j] + 1;
                    parent[i] = j;
                }
            }
            if (divc[i] > maximumLongestCount)
            {
                ansbegins = i;
                maximumLongestCount = divc[i];
            }
        }

        // code very similar to find ultemate parent .
        vector<int> LargestDivisibleSubset;
        while (true)
        {
            LargestDivisibleSubset.push_back(nums[ansbegins]);
            if (ansbegins == parent[ansbegins])
            {
                break;
            }
            else
            {
                ansbegins = parent[ansbegins];
            }
        }
        return LargestDivisibleSubset;
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