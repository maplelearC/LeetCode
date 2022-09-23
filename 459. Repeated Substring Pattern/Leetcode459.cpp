//
// Created by 24191 on 2022/9/23.
//
/*

给定一个非空的字符串s，检查是否可以通过由它的一个子串重复多次构成。

示例 1:
输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。

示例 2:
输入: s = "aba"
输出: false

示例 3:
输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    void getNext(int *next, string &s)
    {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.length(); i++)
        {
            while (j > 1 && s[j] != s[i])
            {
                j = next[j - 1];
            }
            if (s[j] == s[i])
            {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        if (s.length() == 0)
        {
            return false;
        }
        int next[s.length()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s{"aba"};
    Solution s1;
    cout << s1.repeatedSubstringPattern(s);
    return 0;
}