//
// Created by 24191 on 2022/9/21.
//
/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = " hello world "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。

示例 3：
输入：s = "a good  example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string &s)
    {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                while (i < s.size() && s[i] != ' ')
                {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i)
        {
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};


int main()
{
    Solution s1;
    string s{"a good   example"};
    cout << s1.reverseWords(s);
    return 0;
}