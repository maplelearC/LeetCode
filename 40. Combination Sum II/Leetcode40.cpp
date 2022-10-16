//
// Created by 24191 on 2022/10/16.
//
/*
给定一个候选人编号的集合candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。
candidates中的每个数字在每个组合中只能使用一次。
注意：解集不能包含重复的组合。

示例1:
输入: candidates =[10,1,2,7,6,1,5], target =8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例2:
输入: candidates = [2,5,2,1,2], target =5,
输出:
[
[1,2,2],
[5]
]
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int startIndex, vector<bool> &used)
    {
        if (sum == target)
        {
            res.push_back(path);
        }

        for (int i = startIndex; i < candidates.size() and sum + candidates[i] <= target; i++)
        {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum + candidates[i], i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return res;
    }
};