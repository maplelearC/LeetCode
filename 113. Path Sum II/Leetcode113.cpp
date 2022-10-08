//
// Created by 24191 on 2022/10/8.
//
/*
给你二叉树的根节点 root和一个整数目标和 targetSum，找出所有 从根节点到叶子节点
路径总和等于给定目标和的路径。叶子节点 是指没有子节点的节点。

示例 1：
输入：
root =[5,4,8,11,null,13,4,7,2,null,null,5,1],targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：

输入：
root =[1,2,3],targetSum = 5
输出：[]
示例 3：

输入：
root =[1,2],targetSum = 0
输出：[]
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
    int sum = 0;
    vector<int> Path;
    vector<vector<int>> res;

    void traversal(TreeNode *root, int sum, int targetSum)
    {
        if (root->left == nullptr && root->right == nullptr && sum == targetSum)
        {
            res.push_back(Path);
            return;
        }
        if (root->left)
        {
            Path.push_back(root->left->val);
            traversal(root->left, sum += root->left->val, targetSum);
            Path.pop_back();
            sum -= root->left->val;
        }
        if (root->right)
        {
            Path.push_back(root->right->val);
            traversal(root->right, sum += root->right->val, targetSum);
            Path.pop_back();
            sum -= root->right->val;
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        if (root == nullptr) return res;
        Path.push_back(root->val);
        traversal(root, root->val, targetSum);
        return res;
    }
};