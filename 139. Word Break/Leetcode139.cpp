//
// Created by 24191 on 2022/11/9.
//
/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
注意，你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() and dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};


int main()
{
    Solution s1;
    string s = "leetcode";
    vector<string> wordDict{"leet", "code"};
    cout << s1.wordBreak(s, wordDict);
    return 0;
}