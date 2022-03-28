//
// Created by 24191 on 2022/3/28.
//
#include <iostream>

using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        long res = n ^ (n >> 1);
        return (res & (res + 1)) == 0;
    }
};

int main()
{
    int n = 7;
    Solution s1;
    cout << s1.hasAlternatingBits(n);
    return 0;
}

