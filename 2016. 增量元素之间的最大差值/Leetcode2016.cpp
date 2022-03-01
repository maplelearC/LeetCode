#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int res = -1, dif = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] >= nums[j])
                {
                    continue;
                }

                dif = nums[j] - nums[i];
                res = (res > dif) ? res : dif;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {7, 1, 5, 4};
    Solution s1;
    int res = s1.maximumDifference(nums);
    cout << res << endl;
}