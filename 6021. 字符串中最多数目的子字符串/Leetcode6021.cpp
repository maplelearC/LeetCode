//
// Created by 24191 on 2022/3/19.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        long long a = 0, b = 0, res = 0;
        for (int i = 0; i < text.length(); i++)
        {
            char c = text[i];
            if (c == pattern[0])
            {
                a++;
            }
            if (c == pattern[1])
            {
                b++;
                res += a;
            }
        }
        if (pattern[0] == pattern[1])
        {
            return (a + 1) * a / 2;
        }
        long long l = count(text.begin(), text.end(), pattern[0]);
        long long r = count(text.begin(), text.end(), pattern[1]);
        if (l >= r)
        {
            return res + l;
        }
        return res + r;
    }
};

int main()
{
    string text = "aabb", pattern = "ab";
    Solution s1;
    cout << s1.maximumSubsequenceCount(text, pattern);
    return 0;
}
