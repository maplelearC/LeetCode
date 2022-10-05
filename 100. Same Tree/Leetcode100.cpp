//
// Created by 24191 on 2022/10/5.
//
/*
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1：
输入：p = [1,2,3], q = [1,2,3]
输出：true

示例 2：
输入：p = [1,2], q = [1,null,2]
输出：false

示例 3：
输入：p = [1,2,1], q = [1,1,2]
输出：false
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
    bool compare(TreeNode *p, TreeNode *q)
    {
        if (p != nullptr and q == nullptr) return false;
        else if (p == nullptr and q != nullptr) return false;
        else if (p == nullptr and q == nullptr) return true;

        bool left = compare(p->left, q->left);
        bool right = compare(p->right, q->right);

        return left and right;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p != nullptr and q == nullptr) return false;
        else if (p == nullptr and q != nullptr) return false;
        else if (p == nullptr and q == nullptr) return true;
        else if (p->val != q->val) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left and right;
    }
};
