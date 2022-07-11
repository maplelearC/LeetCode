//
// Created by 24191 on 2022/7/11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        while (k)
        {
            if (nums[0] <= 0)
            {
                nums[0] = -nums[0];
                sort(nums.begin(), nums.end());
                k--;
            }
            else
            {
                nums[0] = -nums[0];
                k--;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{
    vector<int> nums{3, -1, 0, 2};
    int k = 3;
    Solution s1;
    cout << s1.largestSumAfterKNegations(nums, k);
    return 0;
}
