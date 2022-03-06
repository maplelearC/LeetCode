#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        vector<int> res;
        for (int i = time; i < security.size(); i++)
        {
            vector<int> l, r;
            for (auto j = i - time; j <= time; j++)
            {
                l.push_back(security[j]);
            }
            for (auto j = time; j <= time; j++)
            {
                r.push_back(security[j]);
            }
            if (!is_sorted(l.begin(), l.end()) && is_sorted(r.begin(), r.end()))
            {
                res.push_back(security[i]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> security{5, 3, 3, 3, 5, 6, 2};
    int time = 2;
    Solution s1;
    cout << s1.goodDaysToRobBank(security, time) << endl;
}