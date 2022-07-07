//
// Created by 24191 on 2022/7/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size(); i += 2)
        {
            if (flowerbed[i] == 0)
            {
                if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)
                {
                    n--;
                }
                else
                {
                    i++;
                }
            }

        }


        return n <= 0;

    }
};

int main()
{
    Solution s1;
    vector<int> flowerbed{0};
    int n = 1;
    bool s;
    s = s1.canPlaceFlowers(flowerbed, n);
    cout << s;
    return 0;
}
