//
// Created by 24191 on 2022/7/6.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> count;
        int ans = 0;

        for (char c: s)
        {
            ++count[c];
        }
        for (auto p: count)
        {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 and ans % 2 == 0)
            {
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    string s{"abccccdd"};
    cout << s1.longestPalindrome(s);
    return 0;
}