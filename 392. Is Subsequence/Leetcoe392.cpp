//
// Created by 24191 on 2022/7/20.
//
#include<iostream>

using namespace std;


class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == n;
    }
};

int main()
{
    Solution s1;
    string s{"abc"}, t{"ahbgdc"};
    cout << s1.isSubsequence(s, t);
    return 0;
}