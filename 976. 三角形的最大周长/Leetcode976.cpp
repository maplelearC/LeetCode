//
// Created by 24191 on 2022/3/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 1; i >= 2; i--)
        {
            if (nums[i - 1] + nums[i - 2] > nums[i])
            {
                return nums[i - 1] + nums[i - 2] + nums[i];
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> nums{1, 2, 1};
    Solution s1;
    cout << s1.largestPerimeter(nums);
    return 0;
}