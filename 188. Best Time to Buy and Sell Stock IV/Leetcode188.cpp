//
// Created by 24191 on 2022/11/11.
//
/*/*
给定一个整数数组 prices ，它的第 i个元素prices[i]是一支给定的股票在第 i天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k笔交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。


示例 1：
输入：
k = 2, prices =[2,4,1]
输出：2
解释：在第 1天 (股票价格 = 2) 的时候买入，在第 2天 (股票价格 = 4)
的时候卖出，这笔交易所能获得利润 = 4 - 2 = 2。

示例 2：
输入：
k = 2, prices =[3,2,6,5,0,3]
输出：7
解释：在第 2天 (股票价格 = 2) 的时候买入，在第 3天 (股票价格 = 6) 的时候卖出,
这笔交易所能获得利润 = 6 - 2 = 4。随后，在第 5天 (股票价格 = 0) 的时候买入，
在第 6天 (股票价格 = 3) 的时候卖出,这笔交易所能获得利润 = 3 - 0 = 3。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        int len = 2 * k + 1;
        for (int i = 1; i < len; i++)
        {
            if (i % 2 != 0)
            {
                dp[0][i] -= prices[0];
            }
        }

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j < len; j++)
            {
                if (j % 2 != 0)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
            }
        }

        return dp[prices.size() - 1][len - 1];
    }
};

int main()
{
    Solution s1;
    vector<int> prices{3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << s1.maxProfit(k, prices);
    return 0;
}