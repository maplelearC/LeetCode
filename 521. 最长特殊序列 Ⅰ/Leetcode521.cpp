#include <iostream>
using namespace std;

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b)
        {
            return -1;
        }
        else
        {
            return max(a.size(), b.size());
        }
    }
};

int main()
{
    string a = "aba", b = "cdc";
    Solution s1;
    cout << s1.findLUSlength(a, b) << endl;
}