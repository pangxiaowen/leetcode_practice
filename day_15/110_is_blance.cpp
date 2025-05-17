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

int get_depth(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int l_d = get_depth(node->left);
    if (l_d == -1)
        return -1;
    int r_d = get_depth(node->right);
    if (r_d == -1)
        return -1;

    int res;
    if (std::abs(l_d - r_d) > 1)
    {
        return -1;
    }
    else
    {
        res = 1 + std::max(l_d, r_d);
    }
    return res;
}

int is_bance(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int l_d = get_depth(node->left);
    if (l_d == -1) // 如果子树不平衡则直接返回
        return -1;
    int r_d = get_depth(node->right);
    if (r_d == -1)
        return -1;

    int res;
    if (std::abs(l_d - r_d) > 1)
    {
        return -1;
    }
    else
    {
        res = 1 + std::max(l_d, r_d);
    }
    return res;
}

bool depth_tree(TreeNode *root)
{

    auto res = get_depth(root);

    return res != -1;
}