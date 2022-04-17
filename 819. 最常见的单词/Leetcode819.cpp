//
// Created by 24191 on 2022/4/17.
//
#include <iostream>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set <string> bannedSet;
        for (auto &word: banned)
        {
            bannedSet.emplace(word);
        }
        int maxFrequency = 0;
        unordered_map<string, int> frequencies;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; i++)
        {
            if (i < length && isalpha(paragraph[i]))
            {
                word.push_back(tolower(paragraph[i]));
            }
            else if (word.size() > 0)
            {
                if (!bannedSet.count(word))
                {
                    frequencies[word]++;
                    maxFrequency = max(maxFrequency, frequencies[word]);
                }
                word = "";
            }
        }
        string mostCommon = "";
        for (auto &[word, frequency]: frequencies)
        {
            if (frequency == maxFrequency)
            {
                mostCommon = word;
                break;
            }
        }
        return mostCommon;
    }
};

int main()
{
    Solution s1;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned{"hit"};
    cout << s1.mostCommonWord(paragraph, banned);
    return 0;
}
