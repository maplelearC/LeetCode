//
// Created by 24191 on 2022/9/15.
//
/*

给你一个 m 行 n 列的矩阵matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include<vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n, 0);
        int x = 0, y = 0;
        int offset = 1;
        int i = 0, j = 0;
        int count = 0;
        while (count < m * n - 1)
        {
            i = x;
            j = y;

            for (j = y; j < n - offset; j++)
            {
                res[count++] = matrix[x][j];
            }

            for (i = x; i < m - offset; i++)
            {
                res[count++] = matrix[i][j];
            }

            for (; j > y && count < n * m; j--)
            {
                res[count++] = matrix[i][j];
            }

            for (; i > x && count < n * m; i--)
            {
                res[count++] = matrix[i][j];
            }
            x++;
            y++;
            offset++;
        }
        if (m == n && m % 2 == 1)
        {
            res[m * n - 1] = matrix[m / 2][n / 2];
        }

        return res;
    }
};


int main()
{
    Solution s1;
    vector<vector<int>> matrix{{1, 2,  3,  4},
                               {5, 6,  7,  8},
                               {9, 10, 11, 12}};
    for (auto s: s1.spiralOrder(matrix))
    {
        cout << s << endl;
    }
    return 0;
}