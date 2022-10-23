//
// Created by 24191 on 2022/10/23.
//
/*
给你两个字符串数组 event1和 event2，表示发生在同一天的两个闭区间时间段事件，其中：
event1 = [startTime1, endTime1]且event2 = [startTime2, endTime2]事件的时间为有效的 24小时制且按 HH:MM 格式给出。
当两个事件存在某个非空的交集时（即，某些时刻是两个事件都包含的），
则认为出现 冲突。
如果两个事件之间存在冲突，返回 true ；否则，返回 false 。

示例 1：
输入：event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
输出：true
解释：两个事件在 2:00 出现交集。

示例 2：
输入：event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
输出：true
解释：两个事件的交集从 01:20 开始，到 02:00 结束。

示例 3：
输入：event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
输出：false
解释：两个事件不存在交集。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int getNum(string time)
    {
        int num = 0;
        int n = 1000;
        for (auto s: time)
        {
            if (s >= '0' && s <= '9')
                num += (s - '0') * n;
            n /= 10;
        }
        return num;
    }

    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        string s1;
        string s2;
        int st1 = getNum(event1[0]);
        int et1 = getNum(event1[1]);
        int st2 = getNum(event2[0]);
        int et2 = getNum(event2[1]);

        if ((st1 <= et2 && et1 >= et2) || (st2 <= et1 && et2 >= et1))
        {

            return true;
        }
        return false;
    }
};