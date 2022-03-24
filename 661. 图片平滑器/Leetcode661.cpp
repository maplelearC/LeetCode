//
// Created by 24191 on 2022/3/24.
//
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = 0, sum = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x >= 0 && x < m && y >= 0 && y < n)
                        {
                            num++;
                            sum += img[x][y];
                        }
                    }
                }
                ret[i][j] = sum / num;
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int> > img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution s1;
    for (auto s: s1.imageSmoother(img))
    {
        for (auto a: s)
        {
            cout << a << endl;
        }
    }
    return 0;
}
