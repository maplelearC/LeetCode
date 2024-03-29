//
// Created by 24191 on 2022/7/30.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> vals;
        while (head != nullptr)
        {
            vals.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = (int) vals.size() - 1; i < j; ++i, --j)
        {
            if (vals[i] != vals[j])
            {
                return false;
            }
        }
        return true;
    }
};
