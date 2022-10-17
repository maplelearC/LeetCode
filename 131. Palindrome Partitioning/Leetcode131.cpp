//
// Created by 24191 on 2022/10/17.
//
/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。

示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

示例 2：
输入：s = "a"
输出：[["a"]]
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;

    void backtracking(const string &s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return res;
    }
};