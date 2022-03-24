//
// Created by 24191 on 2022/3/23.
//
#include <iostream>

using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        char c1 = '#', c2 = c1;
        bool isChange = false;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (isChange)return false;
                else if (c1 == '#')
                {
                    c1 = s1[i];
                    c2 = s2[i];
                }
                else
                {
                    if (c1 == s2[i] && c2 == s1[i])
                    {
                        isChange = true;
                        c2 = '#';
                    }
                    else return false;
                }
            }
        }
        return c2 == '#';
    }
};

int main()
{
    string s1 = "bank", s2 = "kanb";
    Solution S1;
    cout << S1.areAlmostEqual(s1, s2);
    return 0;
}
