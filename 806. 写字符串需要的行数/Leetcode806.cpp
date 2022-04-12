//
// Created by 24191 on 2022/4/12.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int lines = 1;
        int num = 0;
        for (int i = 0; i < widths.size(); i++)
        {
            num += widths[s[i] - 'a'];
            if (num > 100)
            {
                lines++;
                num = widths[s[i] - 'a'];
            }
        }
        return {lines, num};
        /*int lines = 1;
        int width = 0;
        for (auto &c: s)
        {
            int need = widths[c - 'a'];
            width += need;
            if (width > 100)
            {
                lines++;
                width = need;
            }
        }
        return {lines, width};*/
    }
};

int main()
{
    vector<int> widths{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                       10, 10
    };
    string s{"bbbcccdddaaa"};
    Solution s1;
    for (auto s: s1.numberOfLines(widths, s))
    {
        cout << s << endl;
    }
    return 0;
}

