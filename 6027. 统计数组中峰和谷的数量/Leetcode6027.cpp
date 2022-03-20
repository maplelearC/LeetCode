//
// Created by 24191 on 2022/3/20.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int res = 0;
        int l = 1;
        while (l <= nums.size() - 2)
        {
            int r = l + 1;
            while (nums[l] == nums[r] && r < nums.size() - 1)
            {
                r++;
            }
            if (nums[l] > nums[l - 1] && nums[l] > nums[r])
            {
                res++;
            } else if (nums[l] < nums[r] && nums[l] < nums[l - 1])
            {
                res++;

            }
            l = r;
        }
        return res;
    }
};

int main()
{
    vector<int> nums{57, 57, 57, 57, 57, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 85, 85,
                     85, 86, 86, 86};
    Solution s1;
    cout << s1.countHillValley(nums);
    return 0;
}