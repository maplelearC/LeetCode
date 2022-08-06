//
// Created by 24191 on 2022/8/6.
//
#include<iostream>
#include<vector>

using namespace std;


class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> res;
        if (words.size() <= 1)
        {
            return res;
        }
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j && words[j].find(words[i]) != string::npos)
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s1;
    vector<string> words{"mass", "as", "hero", "superhero"};
    for (auto S: s1.stringMatching(words))
    {
        cout << S << endl;
    }
    return 0;
}