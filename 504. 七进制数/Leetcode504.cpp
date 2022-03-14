//
// Created by 24191 on 2022/3/7.
//

#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        bool negative = num < 0;
        num = abs(num);
        string digits;
        while (num > 0) {
            digits.push_back(num % 7 + '0');
            num /= 7;
        }
        if (negative) {
            digits.push_back('-');
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main() {
    int num = 100;
    Solution s1;
    cout << s1.convertToBase7(num) << endl;
    return 0;
}