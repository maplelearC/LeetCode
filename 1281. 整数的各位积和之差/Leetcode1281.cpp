//
// Created by 24191 on 2022/3/18.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, mul = 1;
        while (n > 0) {
            sum += n % 10;
            mul *= n % 10;
            n /= 10;
        }
        return mul - sum;
    }
};

int main() {
    int n = 234;
    Solution s1;
    cout << s1.subtractProductAndSum(n);
    return 0;
}
