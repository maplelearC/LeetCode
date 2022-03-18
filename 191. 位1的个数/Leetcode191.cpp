//
// Created by 24191 on 2022/3/18.
//
#include<iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }
};

int main() {
    uint32_t n = 00000000000000000000000000001011;
    Solution s1;
    cout << s1.hammingWeight(n);
    system("pause");
    return 0;
}