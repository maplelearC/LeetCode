//
// Created by 24191 on 2022/7/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;


class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> ranks;
        vector<int> ans(arr.size());
        for (auto &a: sortedArr)
        {
            if (!ranks.count(a))
            {
                ranks[a] = ranks.size() + 1;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = ranks[arr[i]];
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    vector<int> arr{37, 12, 28, 9, 100, 56, 80, 5, 12};
    for (auto s: s1.arrayRankTransform(arr))
    {
        cout << s << endl;
    }
    return 0;
}