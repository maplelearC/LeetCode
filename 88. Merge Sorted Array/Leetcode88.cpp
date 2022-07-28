//
// Created by 24191 on 2022/7/28.
//
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p1 == -1)
            {
                cur = nums2[p2--];
            }
            else if (p2 == -1)
            {
                cur = nums1[p1--];
            }
            else if (nums1[p1] > nums2[p2])
            {
                cur = nums1[p1--];
            }
            else
            {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

int main()
{
    Solution s1;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    int m = 3;
    int n = 3;
    s1.merge(nums1, m, nums2, n);
    return 0;
}