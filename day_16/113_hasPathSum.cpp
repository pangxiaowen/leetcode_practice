#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution
{
public:
    std::vector<std::vector<int>> res; // 用于记录所有结果
    std::vector<int> path;             // 用于回溯存储

    void traversal(TreeNode *node, int count)
    {
        if (node->left == nullptr && node->right == nullptr && count == 0)
        {
            res.push_back(path);
            return;
        }
        if (node->left == nullptr && node->right == nullptr)
            return;

        if (node->left != nullptr)
        {
            path.push_back(node->left->val);
            traversal(node->left, count - node->left->val);
            path.pop_back();
        }

        if (node->right != nullptr)
        {
            path.push_back(node->right->val);
            traversal(node->right, count - node->right->val);
            path.pop_back();
        }

        return;
    }

    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root != nullptr)
        {
            path.push_back(root->val);
            traversal(root, targetSum - root->val);
        }
        return res;
    }
};