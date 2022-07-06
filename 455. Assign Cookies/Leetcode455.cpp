//
// Created by 24191 on 2022/7/6.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                i++;
            }
            j++;
        }
        return i;
    }
};

int main()
{
    Solution s1;
    vector<int> g{1, 2, 3};
    vector<int> s{1, 1};
    cout << s1.findContentChildren(g, s);
    return 0;
}