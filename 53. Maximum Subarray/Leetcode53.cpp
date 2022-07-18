//
// Created by 24191 on 2022/7/18.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxAns = nums[0];
        for (auto &x: nums)
        {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

int main()
{
    Solution s1;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s1.maxSubArray(nums) << endl;
    return 0;
}