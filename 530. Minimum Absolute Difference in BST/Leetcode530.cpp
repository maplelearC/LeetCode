//
// Created by 24191 on 2022/10/11.
//

/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。

示例 1：
输入：root = [4,2,6,1,3]
输出：1

示例 2：
输入：root = [1,0,48,null,null,12,49]
输出：1
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
    int minVal = INT_MAX;
    TreeNode *pre;

    void traversal(TreeNode *cur)
    {
        if (cur == nullptr) return;
        traversal(cur->left);
        if (pre != nullptr)
        {
            minVal = min(minVal, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);
        return minVal;
    }
};