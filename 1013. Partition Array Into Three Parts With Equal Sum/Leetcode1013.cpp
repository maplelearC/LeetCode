//
// Created by 24191 on 2022/7/13.
//
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int s = accumulate(arr.begin(), arr.end(), 0);
        if (s % 3 != 0)
        {
            return false;
        }
        int target = s / 3;
        int n = arr.size(), i = 0, cur = 0;
        while (i < n)
        {
            cur += arr[i];
            if (cur == target)
            {
                break;
            }
            ++i;
        }
        if (cur != target)
        {
            return false;
        }
        int j = i + 1;
        while (j + 1 < n)
        {
            cur += arr[j];
            if (cur == target * 2)
            {
                return true;
            }
            ++j;
        }
        return false;
    }
};

int main()
{
    Solution s1;
    vector<int> s{0,2,1,-6,6,-7,9,1,2,0,1};
    cout << s1.canThreePartsEqualSum(s);
    return 0;
}


