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

    TreeNode() = default;
    TreeNode(int v) : val(v)
    {
    }
};

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    if (root == nullptr)
        return nullptr;

    if (root->val < low)
    {
        TreeNode *right = trimBST(root->right, low, high);
        return right;
    }

    if (root->val > high)
    {
        TreeNode *left = trimBST(root->left, low, high);
        return left;
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}
