//
// Created by 24191 on 2022/4/26.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int max_val1 = 0, max_val2 = 0;
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                {
                    z++;
                }
                max_val1 = max(max_val1, grid[i][j]);
                max_val2 = max(max_val2, grid[j][i]);
            }
            x += max_val1;
            y += max_val2;
        }

        return x + y + z;
    }
};

int main()
{
    vector<vector<int>> grid{{1, 2}, {3, 4}};
    Solution s1;
    cout << s1.projectionArea(grid);
    return 0;
}
