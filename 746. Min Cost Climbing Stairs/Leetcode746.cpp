//
// Created by 24191 on 2022/7/21.
//

#include <iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        int i = 2;
        while (i <= n)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            i++;
        }
        cout << dp[4];
        return dp[n];
    }
};


int main()
{
    Solution s1;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s1.minCostClimbingStairs(cost);
    return 0;
}
