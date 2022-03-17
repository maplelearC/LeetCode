//
// Created by 24191 on 2022/3/17.
//
#include<iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    double average(vector<int> &salary) {
        sort(salary.begin(), salary.end());
        salary.pop_back();
        salary.erase(salary.begin());
        return (double) accumulate(salary.begin(), salary.end(), 0) / salary.size();
    }
};

int main() {
    vector<int> salary{8000, 9000, 2000, 3000, 6000, 1000};
    Solution s1;
    cout << s1.average(salary);
    return 0;
}
