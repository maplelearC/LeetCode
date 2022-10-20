//
// Created by 24191 on 2022/10/20.
//
/*
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。


示例 1：
输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
输出：["JFK","MUC","LHR","SFO","SJC"]

示例 2：
输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
 */

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_map<string, map<string, int>> targets;

    bool backtracking(int ticketNum, vector<string> &res)
    {
        if (res.size() == ticketNum + 1)
        {
            return true;
        }

        for (pair<const string, int> &target: targets[res[res.size() - 1]])
        {
            if (target.second > 0)
            {
                res.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, res))
                {
                    return true;
                }
                res.pop_back();
                target.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        vector<string> res;
        for (const vector<string> &vec: tickets)
        {
            targets[vec[0]][vec[1]]++;
        }
        res.emplace_back("JFK");
        backtracking(tickets.size(), res);
        return res;
    }
};