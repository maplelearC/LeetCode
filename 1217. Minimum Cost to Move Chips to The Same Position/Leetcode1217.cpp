//
// Created by 24191 on 2022/7/8.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int count1 = 0;
        int count2 = 0;
        for (int pos: position)
        {
            if (pos % 2)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        return min(count1, count2);
    }
};

int main()
{
    Solution s1;
    vector<int> position{2, 3, 3};
    cout << s1.minCostToMoveChips(position) << endl;
    return 0;
}
