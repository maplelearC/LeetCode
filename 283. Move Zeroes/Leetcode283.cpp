//
// Created by 24191 on 2022/8/2.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return;
        }
        int l = nums.size() - 2;
        int r = nums.size() - 1;

        while (l > -1)
        {
            if (nums[l] == 0)
            {
                for (int i = l; i < r; i++)
                {
                    swap(nums[i], nums[i + 1]);
                }
                r--;
            }
            l--;
        }
    }
};

int main()
{
    Solution s1;
    vector<int> nums{0, 1, 0, 3, 12};
    s1.moveZeroes(nums);
    for (auto s: nums)
    {
        cout << s << endl;
    }
    return 0;
}