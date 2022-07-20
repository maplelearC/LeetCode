//
// Created by 24191 on 2022/7/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (!n) return 0;
        int minProfit = prices[0];
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++)
        {
            minProfit = min(minProfit, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minProfit);
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution s1;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s1.maxProfit(prices) << endl;
    return 0;
}
