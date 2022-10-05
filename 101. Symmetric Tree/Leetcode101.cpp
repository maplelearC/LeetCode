//
// Created by 24191 on 2022/10/5.
//
/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。



示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：
输入：root = [1,2,2,null,3,null,3]
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
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr and right != nullptr) return false;
        else if (left != nullptr and right == nullptr) return false;
        else if (left == nullptr and right == nullptr) return true;
        else if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside and inside;
        return isSame;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};