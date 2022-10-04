//
// Created by 24191 on 2022/10/4.
//
/*
给定一棵二叉树的根节点root ，请找出该二叉树中每一层的最大值。

示例1：
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]

示例2：
输入: root = [1,2,3]
输出: [1,3]
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

/*#include<iostream>
#include<queue>
#include<vector>*/
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
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)que.push(root);
        vector<int> res;
        while (!que.empty())
        {
            int size = que.size();
            int max = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                max = node->val > max ? node->val : max;
                if (node->right) que.push(node->right);
                if (node->left) que.push(node->left);
            }
            res.push_back(max);
        }
        return res;
    }
};
