//
// Created by 24191 on 2022/9/27.
//
/*

给你一个由 n 个整数组成的数组nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组[nums[a], nums[b], nums[c], nums[d]]（若两个四元组元素一一对应，则认为两个四元组重复）：
    0 <= a, b, c, d< n
    a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。


示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > target and (nums[k] >= 0 or target >= 0))
            {
                break;
            }

            if (k > 0 and nums[k] == nums[k - 1])
            {
                continue;
            }

            for (int i = k + 1; i < nums.size(); i++)
            {
                if ((long) nums[k] + nums[i] > target and ((long) nums[k] + nums[i] >= 0 or target >= 0))
                {
                    break;
                }
                if (i > k + 1 and nums[i] == nums[i - 1])
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;

                while (right > left)
                {
                    if ((long) nums[k] + nums[i] > target - ((long) nums[right] + nums[left]))
                    {
                        right--;
                        while (left < right and nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }
                    else if ((long) nums[k] + nums[i] < target - ((long) nums[right] + nums[left]))
                    {
                        left++;
                        while (left < right and nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});

                        while (right > left and nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        while (right > left and nums[left] == nums[left + 1])
                        {
                            left++;
                        }

                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};


int main()
{
    Solution s1;
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    for (auto s: s1.fourSum(nums, target))
    {
        for (int a: s)
        {
            cout << a;
        }
        cout << endl;
    }
    return 0;
}
