//
// Created by 24191 on 2022/3/27.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (nums[i] == nums[i + 1]) ans++;
            else i++;
        }
        if ((n - ans) % 2) ans++;
        return ans;
    }
};


int main()
{
    vector<int> nums{1, 1, 2, 3, 5};
    Solution s1;
    cout << s1.minDeletion(nums);
    return 0;
}


