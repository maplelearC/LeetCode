//
// Created by 24191 on 2022/10/26.
//
/*

给定一个区间的集合intervals，其中 intervals[i] = [starti, endi]。返回 需要移除区间的最小数量，使剩余区间互不重叠 。


示例 1:
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> vec;

        int count = 1;
        int end = intervals[intervals.size() - 1][0];
        for (int i = intervals.size() - 2; i >= 0; i--)
        {
            if (end >= intervals[i][1])
            {
                end = intervals[i][0];
                count++;
            }

        }
        return intervals.size() - count;
    }
};

int main()
{
    Solution s1;

    vector<vector<int>> intervals{{-52, 31},
                                  {-73, -26},
                                  {82,  97},
                                  {-65, -11},
                                  {-62, -49},
                                  {95,  99},
                                  {58,  95},
                                  {-31, 49},
                                  {66,  98},
                                  {-63, 2},
                                  {30,  47},
                                  {-40, -26}};

    cout << s1.eraseOverlapIntervals(intervals);
}