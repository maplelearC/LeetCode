//
// Created by 24191 on 2022/7/18.
//

#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int q = 0, p = 0, r = 1;
        for (int i = 1; i <= n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main()
{
    Solution s1;
    int n = 25;
    cout << s1.climbStairs(n);
    return 0;
}