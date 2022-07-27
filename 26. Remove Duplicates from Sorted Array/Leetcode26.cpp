//
// Created by 24191 on 2022/7/27.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int slow = 1, fast = 1;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};


int main()
{
    Solution s1;
    vector<int> nums{1, 1, 2};
    cout << s1.removeDuplicates(nums);
    for (auto s: nums)
    {
        cout << s << endl;
    }
    return 0;
}