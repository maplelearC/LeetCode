//
// Created by 24191 on 2022/4/10.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestInteger(int num)
    {
        vector<int> vec[2];
        for (int t = num; t; t /= 10)
        {
            int x = t % 10;
            vec[x & 1].push_back(-x);
        }
        for (int i = 0; i <= 1; i++) sort(vec[i].begin(), vec[i].end());
        long long ans = 0, p = 1;
        for (int t = num; t; t /= 10, p *= 10)
        {
            int x = t % 10;
            int y = -vec[x & 1].back();
            ans += y * p;
            vec[x & 1].pop_back();
        }
        return ans;
    }
};


int main()
{
    int num = 1234;
    Solution s1;
    cout << s1.largestInteger(num);
    return 0;
}

