//
// Created by 24191 on 2022/7/20.
//
#include<iostream>
#include<vector>

using namespace std;


class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;

    }
};

int main()
{
    Solution s1;
    int n = 5;
    for (auto s: s1.countBits(n))
    {
        cout << s << endl;
    }
    return 0;
}