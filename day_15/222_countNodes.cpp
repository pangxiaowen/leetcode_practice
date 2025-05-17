#include <iostream>
#include <stack>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

void cal_count(TreeNode *node, int &count)
{
    if (node == nullptr)
        return;

    count++;
    cal_count(node->left, count);
    cal_count(node->right, count);
}

int cal_count_v2(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int lc = cal_count_v2(node->left);
    int rc = cal_count_v2(node->right);
    return lc + rc + 1;
}

int cal_count_v3(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    TreeNode *left = node->left;
    TreeNode *right = node->right;

    int ld = 0, rd = 0;
    while (left != nullptr)
    {
        left = left->left;
        ld++;
    }

    while (right != nullptr)
    {
        right = right->right;
        rd++;
    }

    if (ld == rd) // 说明它是一个满二叉树
    {
        return (2 << rd) - 1;
    }

    return cal_count_v3(node->left) + cal_count_v3(node->right) + 1;
}

int countNodes(TreeNode *root)
{
    int res = 0;
    cal_count(root, res);
    return res;
}
