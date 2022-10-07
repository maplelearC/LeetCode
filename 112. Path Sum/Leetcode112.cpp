//
// Created by 24191 on 2022/10/7.
//

/*
给你二叉树的根节点root 和一个表示目标和的整数targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和targetSum 。
如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。

示例 2：
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。
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
    vector<int> Sums;

    void traversal(TreeNode *root, int sum)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            Sums.push_back(sum);
            return;
        }
        if (root->left)
        {
            traversal(root->left, sum += root->left->val);
            sum -= root->left->val;
        }
        if (root->right)
        {
            traversal(root->right, sum += root->right->val);
            sum -= root->right->val;
        }
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)return false;
        traversal(root, root->val);
        return std::find(Sums.begin(), Sums.end(), targetSum) != Sums.end();
    }
};