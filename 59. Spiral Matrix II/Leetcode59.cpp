//
// Created by 24191 on 2022/9/15.
//
/*

给你一个正整数n ，生成一个包含 1 到n^2所有元素，且元素按顺时针顺序螺旋排列的n x n 正方形矩阵 matrix 。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--)
        {
            i = x;
            j = y;

            for (j = y; j < n - offset; j++)
            {
                result[x][j] = count++;
            }

            for (i = x; i < n - offset; i++)
            {
                result[i][j] = count++;
            }

            for (; j > y; j--)
            {
                result[i][j] = count++;
            }

            for (; i > x; i--)
            {
                result[i][j] = count++;
            }
            x++;
            y++;
            offset++;
        }

        if (n % 2)
        {
            result[mid][mid] = count;
        }

        return result;
    }
};

int main()
{
    Solution s1;
    int n = 3;
    for (auto s: s1.generateMatrix(n))
    {
        for (auto a: s)
        {
            cout << a << endl;
        }
    }
    return 0;
}