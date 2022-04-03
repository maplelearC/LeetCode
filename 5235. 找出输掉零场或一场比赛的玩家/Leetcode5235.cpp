//
// Created by 24191 on 2022/4/3.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<int> winner;
        vector<int> low_winner;
        vector<int> loser;
        for (auto &matche: matches)
        {
            winner.push_back(matche[0]);
            loser.push_back(matche[1]);
        }
        sort(winner.begin(), winner.end());
        winner.erase(unique(winner.begin(), winner.end()), winner.end());
        for (int i = 0; i < winner.size(); i++)
        {
            int a = winner[i];
            int j = count(loser.begin(), loser.end(), winner[i]);
            if (count(loser.begin(), loser.end(), winner[i]) == 1)
            {
                low_winner.push_back(winner[i]);
                winner.erase(winner.begin() + i);
                i--;
            }
            if (count(loser.begin(), loser.end(), winner[i]) > 1)
            {
                winner.erase(winner.begin() + i);
                i--;
            }
        }
        for (int i = 0; i < loser.size(); i++)
        {
            if (count(loser.begin(), loser.end(), loser[i]) == 1)
            {
                low_winner.push_back(loser[i]);
            }
        }
        sort(low_winner.begin(), low_winner.end());
        low_winner.erase(unique(low_winner.begin(), low_winner.end()), low_winner.end());
        vector<vector<int> > res;
        res.push_back(winner);
        res.push_back(low_winner);
        return res;
    }
};

int main()
{
    vector<vector<int> > matches{{1, 2},
                                 {2, 1}};
    Solution s1;
    for (auto s: s1.findWinners(matches))
    {
        for (auto a: s)
        {
            cout << a << endl;
        }
    }
    return 0;
}

