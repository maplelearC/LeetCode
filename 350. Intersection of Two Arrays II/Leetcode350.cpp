//
// Created by 24191 on 2022/9/17.
//
/*
给你两个整数数组nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto s: nums1)
        {
            mp[s]++;
        }
        for (auto s: nums2)
        {
            if (mp.count(s))
            {
                res.emplace_back(s);
                mp[s]--;
                if (!mp[s])
                {
                    mp.erase(s);
                }
            }

        }
        return res;
    }
};

int main()
{
    Solution s1;
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    for (auto s: s1.intersect(nums1, nums2))
    {
        cout << s;
    }
    return 0;
}