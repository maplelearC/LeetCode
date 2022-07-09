//
// Created by 24191 on 2022/7/9.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (auto &bill: bills)
        {
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                {
                    return false;
                }
                five--;
                ten++;
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    vector<int> bills{5, 5, 5, 10, 20};
    cout << s1.lemonadeChange(bills) << endl;
    return 0;
}
