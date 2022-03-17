//
// Created by 24191 on 2022/3/17.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + (low & 1 || high & 1);
    }
};

int main() {
    Solution s1;
    int low = 3, high = 7;
    cout << s1.countOdds(low, high);
    return 0;
}
