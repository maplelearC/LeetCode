//
// Created by 24191 on 2022/10/8.
//
/*
给定一个不重复的整数数组nums 。最大二叉树可以用下面的算法从nums 递归地构建:

创建一个根节点，其值为nums 中的最大值。
递归地在最大值左边的子数组前缀上构建左子树。
递归地在最大值 右边 的子数组后缀构建右子树。
返nums 构建的 最大二叉树 。

示例 1：
输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
- [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
- 空数组，无子节点。
- [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
- 空数组，无子节点。
- 只有一个元素，所以子节点是一个值为 1 的节点。
- [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
- 只有一个元素，所以子节点是一个值为 0 的节点。
- 空数组，无子节点。

示例 2：
输入：nums = [3,2,1]
输出：[3,null,2,null,1]
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
    TreeNode *traversal(vector<int> &nums, int begin, int end)
    {
        if (begin > end) return nullptr;

        int index = begin;
        for (int i = begin + 1; i <= end; i++)
        {
            if (nums[i] > nums[index])
            {
                index = i;
            }
        }

        TreeNode *root = new TreeNode(nums[index]);


        root->left = traversal(nums, begin, index - 1);
        root->right = traversal(nums, index + 1, end);

        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size() - 1);
    }
};