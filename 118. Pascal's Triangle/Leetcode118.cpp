//
// Created by 24191 on 2022/7/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;

        ans.push_back({1});
        if (numRows == 1)
        {
            return ans;
        }
        else
        {
            for (int i = 1; i < numRows; i++)
            {
                ans.push_back({1});
                for (int j = 1; j < ans[i - 1].size(); j++)
                {
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
                ans[i].push_back(1);
            }
            return ans;
        }

    }
};

int main()
{
    Solution s1;
    int numRows = 5;
    for (auto a: s1.generate(numRows))
    {
        cout << "\n";
        for (auto s: a)
        {
            cout << s;
        }
    }
    return 0;
}