//
// Created by 24191 on 2022/3/21.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int cnt = 0;
        for (auto s: nums)
        {
            if (s == 0)
            {
                return 0;
            }
            if (s < 0)
            {
                cnt++;
            }
        }
        return cnt & 1 ? -1 : 1;
    }
};

int main()
{
    vector<int> nums{9, 72, 34, 29, -49, -22, -77, -17, -66, -75, -44, -30, -24};
    Solution s1;
    cout << s1.arraySign(nums) << endl;
    return 0;
}
