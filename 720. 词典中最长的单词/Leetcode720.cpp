//
// Created by 24191 on 2022/3/17.
//
#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() != b.size() ? a.size() < b.size() : a > b;
        });
        string longest;
        unordered_set<string> candidates = {""};
        for (const auto &word: words) {
            if (candidates.count(word.substr(0, word.size() - 1))) {
                candidates.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};


int main() {
    vector<string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};
    Solution s1;
    cout << s1.longestWord(words);
    return 0;
}