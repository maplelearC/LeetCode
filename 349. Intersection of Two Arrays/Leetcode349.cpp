//
// Created by 24191 on 2022/9/17.
//
/*
给定两个数组nums1和nums2 ，返回 它们的交集。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> res;
        unordered_set<int> nums(nums1.begin(), nums1.end());
        for (auto num: nums2)
        {
            if (nums.find(num) != nums.end())
            {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};


int main()
{
    Solution s1;
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    for (auto s: s1.intersection(nums1, nums2))
    {
        cout << s;
    }
    return 0;
}
