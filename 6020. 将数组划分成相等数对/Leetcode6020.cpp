//
// Created by 24191 on 2022/3/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    vector<int> nums{3, 2, 3, 2, 2, 2};
    Solution s1;
    bool is = s1.divideArray(nums);
    cout << is << endl;
    return 0;
}


