#include <bits/stdc++.h>
#define ll long long int
#define float double
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        f(n, 1, k);
        return ans;
    }
    void f(int n, int i, int k)
    {
        if (n == 0 && temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        if (n <= 0 || i == 10)
        {
            return;
        }
        // include
        temp.push_back(i);
        f(n - i, i + 1, k);
        temp.pop_back();
        // not include
        f(n, i + 1, k);
    }
};

int main()
{

    return 0;
}