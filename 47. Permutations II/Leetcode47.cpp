//
// Created by 24191 on 2022/10/19.
//
/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
[1,2,1],
[2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() >= nums.size())
        {
            res.push_back(path);
            return;
        }

        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end() || used[i])
            {
                continue;
            }
            path.push_back(nums[i]);
            set.insert(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};