//
// Created by 24191 on 2022/11/16.
//

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;

        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};

int main()
{
    Solution s1;
    vector<int> nums1{2, 5, 1, 2, 5}, num2{10, 5, 2, 1, 5, 2};
    cout << s1.maxUncrossedLines(nums1, nums1) << endl;
    return 0;
}