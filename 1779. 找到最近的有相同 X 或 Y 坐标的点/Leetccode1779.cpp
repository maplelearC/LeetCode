//
// Created by 24191 on 2022/3/19.
//
//
// Created by 24191 on 2022/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int index = -1;
        int min = INT_MAX;
        for (int i = 0, now; i < points.size(); i++)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                now = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (now < min)
                {
                    min = now;
                    index = i;
                }
            }
        }
        return index;
    }
};

int main()
{
    vector<vector<int> >
            points{{1, 2},
                   {3, 1},
                   {2, 4},
                   {2, 3},
                   {4, 4}};
    int x = 3, y = 4;
    Solution s1;
    cout << s1.nearestValidPoint(x, y, points);
    return 0;
}

