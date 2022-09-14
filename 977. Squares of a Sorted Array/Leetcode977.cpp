//
// Created by 24191 on 2022/9/14.
//
/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
*/
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 0);
        int k = n - 1;
        for (int i = 0, j = n - 1; i <= j;)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                res[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                res[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};