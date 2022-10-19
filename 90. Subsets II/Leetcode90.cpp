//
// Created by 24191 on 2022/10/18.
//
/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
输入：nums = [0]
输出：[[],[0]]
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{

public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex)
    {
        res.push_back(path);
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); ++i)
        {
            if (uset.find(nums[i]) != uset.end())
            {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
};
