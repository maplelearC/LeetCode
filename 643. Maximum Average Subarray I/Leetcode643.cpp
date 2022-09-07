//
// Created by 24191 on 2022/8/6.
//

#include<iostream>
#include<vector>

using namespace std;


class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < n; i++)
        {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};

int main()
{
    Solution s1;
    vector<int> nums{0, 1, 1, 3, 3};
    int k = 4;
    cout << s1.findMaxAverage(nums, k) << endl;
    return 0;
}