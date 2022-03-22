//
// Created by 24191 on 2022/3/22.
//
#include <iostream>

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int acnt = 0, bcnt = 0;
        if (colors.length() <= 2)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < colors.length() - 2; i++)
            {
                if (colors[i] == 'A' && colors[i + 1] == 'A' && colors[i + 2] == 'A')
                {
                    acnt++;
                }
                if (colors[i] == 'B' && colors[i + 1] == 'B' && colors[i + 2] == 'B')
                {
                    bcnt++;
                }
            }
        }
        return (acnt > bcnt);
    }
};

int main()
{
    string colors = "BBBAAAABB";
    Solution s1;
    cout << s1.winnerOfGame(colors);
    return 0;
}
