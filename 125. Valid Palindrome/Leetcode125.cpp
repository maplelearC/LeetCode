//
// Created by 24191 on 2022/7/29.
//

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string sgood;
        for (char ch: s)
        {
            if (isalnum(ch))
            {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (sgood[left] != sgood[right])
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    string s{"0P"};
    Solution s1;
    cout << s1.isPalindrome(s) << endl;
    return 0;
}