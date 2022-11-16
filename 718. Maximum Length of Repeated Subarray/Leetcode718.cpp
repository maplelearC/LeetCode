//
// Created by 24191 on 2022/11/16.
//
/*
给两个整数数组nums1和nums2，返回 两个数组中 公共的 、长度最长的子数组的长度。

示例 1：
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。

示例 2：
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums1{1, 2, 3, 2, 1};
    vector<int> nums2{3, 2, 1, 4, 7};
    Solution s1;
    cout << s1.findLength(nums1, nums2);
    return 0;
}