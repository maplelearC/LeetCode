//
// Created by 24191 on 2022/9/21.
//
/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res;
        for (auto a: s)
        {
            if (a == ' ')
            {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else
            {
                res.push_back(a);
            }
        }
        return res;
    }
};

int main()
{
    string s{"We are happy."};
    Solution s1;
    cout << s1.replaceSpace(s);
    return 0;
}