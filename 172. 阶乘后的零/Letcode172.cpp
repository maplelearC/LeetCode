//
// Created by 24191 on 2022/3/25.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        for (int i = 5; i <= n; i += 5)
        {
            for (int x = i; x % 5 == 0; x /= 5)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    int n = 10000;
    Solution s1;
    cout << s1.trailingZeroes(n);
    return 0;
}

