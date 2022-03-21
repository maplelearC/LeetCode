//
// Created by 24191 on 2022/3/21.
//
#include <iostream>
#include<cmath>

using namespace std;

class Solution
{
public:
    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};

int main()
{
    int n = 19;
    Solution s1;
    cout << s1.isHappy(n);
    return 0;
}