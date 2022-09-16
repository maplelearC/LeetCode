//
// Created by 24191 on 2022/9/16.
//
/*

给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int record[26]{0};
        for (auto i: magazine)
        {
            record[i - 'a']++;
        }
        for (auto i: ransomNote)
        {
            record[i - 'a']--;
        }
        for (auto i: record)
        {
            if (i < 0)
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
    string ransomNote = "aa", magazine = "aab";
    cout << s1.canConstruct(ransomNote, magazine);
    return 0;
}
