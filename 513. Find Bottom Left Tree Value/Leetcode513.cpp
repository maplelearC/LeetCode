//
// Created by 24191 on 2022/10/7.
//
/*
给定一个二叉树的 根节点 root，请找出该二叉树的最底层最左边节点的值。
假设二叉树中至少有一个节点。

示例 1:
输入: root = [2,1,3]
输出: 1

示例 2:
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxLen = INT_MAX;
    int maxleftValue;

    void traversal(TreeNode *root, int leftLen)
    {
        if (root->left == nullptr and root->right == nullptr)
        {
            if (leftLen > maxLen)
            {
                maxLen = leftLen;
                maxleftValue = root->val;
            }
            return;
        }

        if (root->left)
        {
            leftLen++;
            traversal(root->left, leftLen + 1);
            leftLen--;
        }
        if (root->right)
        {
            leftLen++;
            traversal(root->right, leftLen + 1);
            leftLen--;
        }
    }

    int findBottomLeftValue(TreeNode *root)
    {
        traversal(root, 0);
        return maxleftValue;
    }

};
