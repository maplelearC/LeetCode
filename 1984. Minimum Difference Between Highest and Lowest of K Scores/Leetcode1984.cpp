//
// Created by 24191 on 2022/8/7.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + k - 1 < nums.size(); i++)
        {
            res = min(res, nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};

int main()
{
    Solution s1;
    vector<int> nums{87063, 61094, 44530, 21297, 95857, 93551, 99186};
    int k = 6;
    cout << s1.minimumDifference(nums, k) << endl;
    return 0;
}