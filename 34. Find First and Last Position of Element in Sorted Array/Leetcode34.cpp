//
// Created by 24191 on 2022/9/7.
//

/*给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回[-1, -1]。

你必须设计并实现时间复杂度为O(log n)的算法解决此问题。


示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int GetRight(vector<int> &nums, int target)
    {
        int Right = -2;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
                Right = left;
            }
        }
        return Right;
    }

    int GetLeft(vector<int> &nums, int target)
    {
        int Left = -2;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                Left = right;
            }
        }
        return Left;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = GetLeft(nums, target);
        int right = GetRight(nums, target);
        if (left == -2 || right == -2)
        {
            return {-1, -1};
        }
        if (right - left > 1)
        {
            return {left + 1, right - 1};
        }
        return {-1, -1};
    }
};


int main()
{
    Solution s1;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    for (auto s: s1.searchRange(nums, target))
    {
        cout << s << "\n";
    }
    return 0;
}