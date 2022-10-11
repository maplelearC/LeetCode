//
// Created by 24191 on 2022/10/11.
//
/*
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
如果树中有不止一个众数，可以按 任意顺序 返回。
假定 BST 满足如下定义：
结点左子树中所含节点的值 小于等于 当前节点的值
结点右子树中所含节点的值 大于等于 当前节点的值
左子树和右子树都是二叉搜索树

示例 1：
输入：root = [1,null,2,2]

输出：[2]
示例 2：
输入：root = [0]
输出：[0]
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
private:
    int maxCount; // 最大频率
    int count; // 统计频率
    TreeNode *pre;
    vector<int> result;

    void searchBST(TreeNode *cur)
    {
        if (cur == NULL) return;

        searchBST(cur->left);       // 左
        // 中
        if (pre == NULL)
        { // 第一个节点
            count = 1;
        }
        else if (pre->val == cur->val)
        { // 与前一个节点数值相同
            count++;
        }
        else
        { // 与前一个节点数值不同
            count = 1;
        }
        pre = cur; // 更新上一个节点

        if (count == maxCount)
        { // 如果和最大值相同，放进result中
            result.push_back(cur->val);
        }

        if (count > maxCount)
        { // 如果计数大于最大值频率
            maxCount = count;   // 更新最大频率
            result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            result.push_back(cur->val);
        }

        searchBST(cur->right);      // 右
        return;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        count = 0;
        maxCount = 0;
        TreeNode *pre = NULL; // 记录前一个节点
        result.clear();

        searchBST(root);
        return result;
    }
};