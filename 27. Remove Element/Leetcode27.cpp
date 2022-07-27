//
// Created by 24191 on 2022/7/27.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        int fast = n, slow = 0;

        while (fast > slow)
        {
            if (nums[slow] == val)
            {
                nums[slow] = nums[fast - 1];
                fast--;
            }
            else
            {
                slow++;
            }
        }
        return slow;
    }
};

int main()
{
    Solution s1;
    vector<int> nums{3, 2, 2, 3};
    int val = 3;

    cout << s1.removeElement(nums, val);
    for (auto s: nums)
    {
        cout << s << endl;
    }
    return 0;
}