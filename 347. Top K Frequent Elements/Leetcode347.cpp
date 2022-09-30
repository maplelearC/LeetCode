//
// Created by 24191 on 2022/9/30.
//
/*

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> rhs)
        {
            return lhs.second > rhs.second;
        }
    };


    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;

        for (auto s: nums)
        {
            mp[s]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }

        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};


int main()
{
    Solution s1;
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    for (auto s: s1.topKFrequent(nums, k))
    {
        cout << s << endl;
    }
    return 0;
}