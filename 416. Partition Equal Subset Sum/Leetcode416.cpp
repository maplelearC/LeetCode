//
// Created by 24191 on 2022/11/3.
//
/*
给你一个 只包含正整数 的 非空 数组nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int res;
        for (int num: nums)
        {
            res += num;
        }

        if (res % 2 == 1)
            return false;

        vector<int> dp(10001, 0);


        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = res / 2; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[res / 2] == res / 2)return true;

        return false;
    }
};

int main()
{
    Solution s1;
    vector<int> nums{1, 1, 1, 5, 5, 11};
    cout << s1.canPartition(nums);
    return 0;
}
