//
// Created by 24191 on 2022/11/11.
//
/*
给定一个整数数组prices，其中第prices[i]表示第i天的股票价格 。
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入: prices = [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

示例 2:
输入: prices = [1]
输出: 0
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][1] -= prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = dp[i - 1][2];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        }
        for (auto s: dp)
        {
            for (auto a: s)
            {
                cout << a << " ";
            }
            cout << "\n";
        }
        return dp[prices.size() - 1][2];
    }
};

int main()
{
    Solution s1;
    vector<int> prices{1, 2, 3, 0, 2};
    cout << s1.maxProfit(prices);
    return 0;
}