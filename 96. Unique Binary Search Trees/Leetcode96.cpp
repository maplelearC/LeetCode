//
// Created by 24191 on 2022/11/2.
//

/*
给你一个整数 n，求恰由 n个节点组成且节点值从 1到 n互不相同的 二叉搜索树
有多少种？返回满足题意的二叉搜索树的种数。

示例 1：
输入：
n = 3
输出：5

示例 2：
输入：
n = 1
输出：1
*/

#include<iostream>
#include<vector>

using namespace std;


class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s1;
    int n = 3;
    cout << s1.numTrees(n);
    return 0;
}