//
// Created by 24191 on 2022/3/31.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    bool isSelfDividing(int num)
    {
        int temp = num;
        while (temp > 0)
        {
            int digit = temp % 10;
            if (digit == 0 || num % digit != 0)
            {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int i = left; i <= right; i++)
        {
            if (isSelfDividing(i))
            {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

int main()
{
    int left = 1, right = 22;
    Solution s1;
    for (auto s: s1.selfDividingNumbers(left, right))
    {
        cout << s << endl;
    }
    return 0;
}

