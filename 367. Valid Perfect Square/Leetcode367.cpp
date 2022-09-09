//
// Created by 24191 on 2022/9/7.
//

/*
  给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如sqrt 。

示例 1：
输入：num = 16
输出：true

示例 2：
输入：num = 14
输出：false
*/


class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int l = 1;
        int r = num;
        while (l <= r)
        {
            double mid = (r - l) / 2 + l;
            if ((long) mid * mid < num)
            {
                l = mid + 1;
            }
            else if ((long) mid * mid > num)
            {
                r = mid - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};


