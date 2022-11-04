//
// Created by 24191 on 2022/11/4.
//
/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string str: strs)
        {
            int one = 0, zero = 0;
            for (char s: str)
            {
                if (s == '0')zero++;
                else one++;
            }
            for (int i = m; i >= zero; i--)
            {
                for (int j = n; j >= one; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        for (auto s: dp)
        {
            for (auto d: s)
            {
                cout << d << "";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s1;
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << s1.findMaxForm(strs, m, n);
    return 0;
}