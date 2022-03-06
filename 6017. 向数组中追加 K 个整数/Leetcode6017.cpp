
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = unique(nums.begin(), nums.end()) - nums.begin(); // 所谓的去重只是把多余的数移到了最后面并没有删除
        long long d = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= k)
            {
                d += nums[i];
                ++k;
            }
        }
        return (1LL + k) * k / 2 - d;
    }
};
