//
// Created by 24191 on 2022/10/23.
//
/*给你一个整数数组 nums 和一个整数 k ，请你统计并返回 nums 的子数组中元素的最大公因数等于 k 的子数组数目。
子数组 是数组中一个连续的非空序列。
数组的最大公因数 是能整除数组中所有元素的最大整数。

示例 1：
入：nums = [9,3,1,2,6,3], k = 3
输出：4
解释：nums 的子数组中，以 3 作为最大公因数的子数组如下：
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]

示例 2：
输入：nums = [4], k = 7
输出：0
解释：不存在以 7 作为最大公因数的子数组。*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        // 枚举子数组的起点
        for (int i = 0; i < n; i++)
        {
            int g = nums[i];
            // 枚举子数组的终点
            for (int j = i; j < n; j++)
            {
                // 计算最大公因数
                g = __gcd(g, nums[j]);
                if (g == k) ans++;
                else if (g < k) break;
            }
        }
        return ans;
    }
};
