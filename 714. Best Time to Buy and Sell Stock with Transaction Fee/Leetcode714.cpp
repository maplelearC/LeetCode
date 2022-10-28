//
// Created by 24191 on 2022/10/28.
//
/*
给定一个整数数组prices，其中第i个元素代表了第i天的股票价格 ；非负整数fee代表了交易股票的手续费用。
你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
返回获得利润的最大值。
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:
输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:
在此处买入prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润:((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int res = 0;
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }

            if (prices[i] > minPrice + fee)
            {
                res += prices[i] - (minPrice + fee);
                minPrice = prices[i] - fee;
            }
        }
        return res;
    }
};

int main()
{
    Solution s1;
    vector<int> prices{1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << s1.maxProfit(prices, fee);
    return 0;
}