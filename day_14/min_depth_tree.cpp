#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

int depth(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int l_d = depth(node->left);
    int r_d = depth(node->right);

    if (node->left == nullptr && node->right != nullptr)
    {
        return r_d + 1;
    }
    else if (node->left != nullptr && node->right == nullptr)
    {
        return l_d + 1;
    }
}

int min_depth_tree(TreeNode *root)
{
}