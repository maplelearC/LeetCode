//
// Created by 24191 on 2022/7/7.
//

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2)
        {
            ans+=nums[i];
        }
        return ans;
    }
};


int main()
{
    Solution s1;
    vector<int> nums{1, 4, 3, 2};
    cout << s1.arrayPairSum(nums);
    return 0;
}