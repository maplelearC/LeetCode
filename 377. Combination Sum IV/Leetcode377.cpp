//
// Created by 24191 on 2022/11/6.
//
/*
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
题目数据保证答案符合 32 位整数范围。

示例 1：
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

示例 2：
输入：nums = [9], target = 3
输出：0
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    int target = 4;
    Solution s1;
    cout << s1.combinationSum4(nums, target);
    return 0;
}