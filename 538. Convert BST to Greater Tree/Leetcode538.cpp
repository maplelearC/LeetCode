//
// Created by 24191 on 2022/10/13.
//
/*

给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node的新值等于原树中大于或等于node.val的值之和。
提醒一下，二叉搜索树满足下列约束条件：
节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
注意：本题和 1038:https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同


示例 1：
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

示例 2：
输入：root = [0,null,1]
输出：[1,null,1]

示例 3：
输入：root = [1,0,2]
输出：[3,3,2]

示例 4：
输入：root = [3,2,4,1]
输出：[7,9,4,10]
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
    int pre;

    void traversal(TreeNode *root)
    {
        if (!root)return;
        traversal(root->right);
        pre += root->val;
        root->val = pre;
        traversal(root->left);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        pre = 0;
        traversal(root);
        return root;
    }
};