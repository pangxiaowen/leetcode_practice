
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

class TreeNode
{
  public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

TreeNode *lowest_common_ancestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == q || root == p || root == nullptr)
        return root;

    TreeNode *left = lowest_common_ancestor(root->left, p, q);
    TreeNode *right = lowest_common_ancestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }

    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
}