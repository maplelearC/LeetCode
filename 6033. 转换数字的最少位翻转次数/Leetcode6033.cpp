//
// Created by 24191 on 2022/4/2.
//
#include<iostream>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (start % 2 != goal % 2)
            {
                res++;
            }
            start /= 2;
            goal /= 2;
        }
        return res;
    }
};

int main()
{
    int start = 10, goal = 7;
    Solution s1;
    cout << s1.minBitFlips(start, goal) << endl;
    return 0;
}
