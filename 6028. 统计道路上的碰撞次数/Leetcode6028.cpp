//
// Created by 24191 on 2022/3/20.
//
#include <iostream>

using namespace std;


class Solution
{
public:
    int countCollisions(string directions)
    {
        int ans = 0;
        bool flag = false;
        for (char c: directions)
        {
            if (c == 'R' || c == 'S')
            {
                flag = true;
            }
            else if (flag)
            {
                ans++;
            }
        }
        flag = false;
        for (int i = (int) directions.size() - 1; i >= 0; i--)
        {
            char c = directions[i];
            if (c == 'L' || c == 'S')
            {
                flag = true;
            }
            else if (flag)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    string directions = "RLRSLL";
    Solution s1;
    cout << s1.countCollisions(directions);
    return 0;
}