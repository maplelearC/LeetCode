//
// Created by 24191 on 2022/11/10.
//
/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为root。
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的root。返回在不触动警报的情况下，小偷能够盗取的最高金额。



示例 1:
输入: root = [3,2,3,null,3,null,1]
输出: 7
解释:小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7

示例 2:
输入: root = [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
*/


//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include<bits/stdc++.h>


using namespace std;

class Solution
{
public:
    vector<int> robTree(TreeNode *root)
    {
        if (root == nullptr)return vector<int>{0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);

        int val1 = root->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {val2, val1};
    }

    int rob(TreeNode *root)
    {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};
