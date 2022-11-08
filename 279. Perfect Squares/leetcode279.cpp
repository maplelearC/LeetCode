//
// Created by 24191 on 2022/11/8.
//
/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例1：
输入：n = 12
输出：3
解释：12 = 4 + 4 + 4

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
*/
#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                if (j - i * i >= 0)
                    dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s1;
    int n = 12;
    cout << s1.numSquares(n);
    return 0;
}