//
// Created by 24191 on 2022/4/7.
//
#include <iostream>

using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

int main()
{
    string s = "abcde", goal = "abced";
    Solution s1;
    cout << s1.rotateString(s, goal);
    return 0;
}
