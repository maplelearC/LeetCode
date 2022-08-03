//
// Created by 24191 on 2022/8/3.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

int main()
{
    Solution s1;
    vector<char> s{'h', 'e', 'l', 'l', 'o'};
    s1.reverseString(s);
    for (auto a: s)
    {
        cout << a << endl;
    }
    return 0;
}