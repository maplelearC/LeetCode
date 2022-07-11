//
// Created by 24191 on 2022/7/11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        vector<int> nums;
        int l = 0;
        int r = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I' && l < r)
            {
                nums.push_back(l);
                l++;
            }
            if (s[i] == 'D' && l < r)
            {
                nums.push_back(r);
                r--;
            }
        }
        nums.push_back(l);
        return nums;
    }
};

int main()
{
    string S{"IDID"};
    Solution s1;
    for (auto a: s1.diStringMatch(S))
    {
        cout << a << '\n';
    }
    return 0;
}


