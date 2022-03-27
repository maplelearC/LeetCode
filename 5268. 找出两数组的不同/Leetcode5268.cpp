//
// Created by 24191 on 2022/3/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int> > answer;
        vector<int> num1, num2;
        for (int &i: nums1)
        {
            if (count(nums2.begin(), nums2.end(), i) == 0)
            {
                if (count(num1.begin(), num1.end(), i) == 0)
                    num1.push_back(i);
            }
        }
        for (int &i: nums2)
        {
            if (count(nums1.begin(), nums1.end(), i) == 0)
            {
                if (count(num2.begin(), num2.end(), i) == 0)
                    num2.push_back(i);
            }
        }
        answer.push_back(num1);
        answer.push_back(num2);
        return answer;
    }
};

int main()
{
    vector<int> nums1{1, 2, 3}, nums2{2, 4, 6};
    Solution s1;
    for (int i = 0; i < s1.findDifference(nums1, nums2).size(); i++)
    {
        for (int j = 0; j < s1.findDifference(nums1, nums2)[0].size(); j++)
        {
            cout << s1.findDifference(nums1, nums2)[i][j];
        }
    }
    return 0;
}


