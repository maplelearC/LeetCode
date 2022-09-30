//
// Created by 24191 on 2022/9/30.
//
/*

给定一个二叉树的根节点 root ，返回 它的 中序遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


#include<iostream>
#include<vector>

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
    void inTraversal(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        res.push_back(root->val);
        inTraversal(root->left, res);
        inTraversal(root->right, res);

    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inTraversal(root, res);
        return res;
    }
};
