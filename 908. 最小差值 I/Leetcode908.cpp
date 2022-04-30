//
// Created by 24191 on 2022/4/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    int smallestRangeI(vector<int> &nums, int k)
    {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;

    }
};

int main()
{
    vector<int> nums{1};
    int k = 0;
    Solution s1;
    cout << s1.smallestRangeI(nums, k) << endl;
    return 0;
}