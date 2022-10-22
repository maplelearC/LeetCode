//
// Created by 24191 on 2022/10/22.
//
/*
给你一个非负整数数组nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。

示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
从下标为 0 跳到下标为 1 的位置，跳1步，然后跳3步到达数组的最后一个位置。

示例 2:
输入: nums = [2,3,0,1,4]
输出: 2
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int count = 0;
        int curCover = 0;
        int cover = 0;
        if (nums.size() == 1)return count;
        for (int i = 0; i < nums.size(); i++)
        {
            cover = max(i + nums[i], cover);

            if (i == curCover)
            {
                if (curCover != nums.size() - 1)
                {
                    count++;
                    curCover = cover;
                    if (cover >= nums.size() - 1) break;
                }
                else break;
            }
        }
        return count;
    }
};