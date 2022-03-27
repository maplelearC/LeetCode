//
// Created by 24191 on 2022/3/27.
//
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int sum = mean * (n + m);
        int missingSum = sum;
        for (int &roll: rolls)
        {
            missingSum -= roll;
        }
        if (missingSum < n || missingSum > 6 * n)
        {
            return {};
        }
        int quotient = missingSum / n, remainder = missingSum % n;
        vector<int> missing(n);
        for (int i = 0; i < n; i++)
        {
            missing[i] = quotient + (i < remainder ? 1 : 0);
        }
        return missing;
    }
};

int main()
{
    vector<int> rolls{6, 3, 4, 3, 5, 3};
    Solution s1;
    int mean = 1, n = 6;
    for (auto s: s1.missingRolls(rolls, mean, n))
    {
        cout << s;
    }
    return 0;
}