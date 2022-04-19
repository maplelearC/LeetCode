//
// Created by 24191 on 2022/4/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size();
        vector<int> res(n);
        int last = -1;
        for (int i = 0, j = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                while (j < i)
                {
                    if (last != -1) res[j] = min(i - j, j - last);
                    else res[j] = i - j;
                    j++;
                }
                last = i;
            }
        }

        if (last != n - 1)
        {
            for (int i = last + 1; i < n; i++)
            {
                res[i] = i - last;
            }
        }

        return res;
    }
};

int main()
{
    string s = "loveleetcode";
    char c = 'e';
    Solution s1;
    for (auto a: s1.shortestToChar(s, c))
    {
        cout << a;
    }
    return 0;
}

