#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long ret = 0;
        for (int i = 0; i < n; i++)
        {
            int minVal = INT_MAX, maxVal = INT_MIN;
            for (int j = i; j < n; j++)
            {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                ret += maxVal - minVal;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution s1;
    cout << s1.subArrayRanges(nums) << endl;
}