//
// Created by 24191 on 2022/10/15.
//
/*

给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按任意顺序返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    const string letterMap[10] = {
            "",
            "",
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
    };
public:
    vector<string> res;
    string s;

    void backtracking(const string &digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++)
        {
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return res;
        backtracking(digits, 0);
        return res;
    }
};