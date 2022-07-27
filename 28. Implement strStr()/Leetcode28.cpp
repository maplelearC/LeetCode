//
// Created by 24191 on 2022/7/27.
//
#include<iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++)
        {
            int j = i, k = 0;
            while (k < m and haystack[j] == needle[k])
            {
                j++;
                k++;
            }
            if (k == m) return i;
        }
        return -1;
    }
};

int main()
{
    string haystack{"hello"};
    string needle{"ll"};
    Solution s1;
    cout << s1.strStr(haystack, needle) << endl;
    return 0;
}