#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = security.size();
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            if (security[n - i - 1] <= security[n - i]) {
                right[n - i - 1] = right[n - i] + 1;
            }
        }

        vector<int> ans;
        for (int i = time; i < n - time; i++) {
            if (left[i] >= time && right[i] >= time) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> security{5, 3, 3, 3, 5, 6, 2};
    int time = 2;
    Solution s1;
    vector<int> s2 = s1.goodDaysToRobBank(security, time);
    for (int i = 0; i < s2.size(); i++) {
        cout << s2[i];
    }
}