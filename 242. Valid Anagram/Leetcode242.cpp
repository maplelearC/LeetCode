//
// Created by 24191 on 2022/9/16.
//
/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若s 和 t中每个字符出现的次数都相同，则称s 和 t互为字母异位词。

示例1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false
*/

#include<iostream>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;
        int arrayS[26]{0};
        int arrayT[26]{0};
        for (char i: s)
        {
            arrayS[i - 'a']++;
        }
        for (char i: t)
        {
            arrayT[i - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arrayT[i] != arrayS[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    string s = "anagram", t = "nagaram";
    cout << s1.isAnagram(s, t);
    return 0;
}