//
// Created by 24191 on 2022/4/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        while (nums.size() != 1)
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    Solution s1;
    cout << s1.triangularSum(nums);
    return 0;
}

