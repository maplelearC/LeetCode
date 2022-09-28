//
// Created by 24191 on 2022/9/28.
//
/*

给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例2：
输入：s = "()[]{}"
输出：true

示例3：
输入：s = "(]"
输出：false
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(')');
            }
            else if (s[i] == '{')
            {
                st.push('}');
            }
            else if (s[i] == '[')
            {
                st.push(']');
            }
            else if (st.empty() || st.top() != s[i])
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        return st.empty();
    }
};


int main()
{
    string s{"()[]{}"};
    Solution s1;
    cout << s1.isValid(s) << "\n";
    return 0;
}