//
// Created by 24191 on 2022/10/28.
//
/*
以数组 intervals表示若干个区间的集合，其中单个区间为intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        vector<vector<int>> res;

        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>> intervals{{1,  3},
                                  {2,  6},
                                  {8,  10},
                                  {15, 18}};

    for (auto s: s1.merge(intervals))
    {
        for (auto a: s)
        {
            cout << a << endl;
        }
    }
    return 0;
}