//
// Created by 24191 on 2022/3/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size() - 1; ++i)
        {
            if (arr[i] * 2 != arr[i - 1] + arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> arr{-13, -17, -8, -10, -20, 2, 3, -19, 2, -18, -5, 7, -12, 18, -17, 12, -1};
    Solution s1;
    cout << s1.canMakeArithmeticProgression(arr);
    return 0;
}