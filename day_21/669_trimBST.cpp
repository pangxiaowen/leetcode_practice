#include <algorithm>
#include <ios>
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
    TreeNode(int v) : val(v) {}
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

TreeNode *Traversal(TreeNode *root, int low, int high)
{
    if (root == nullptr)
        return root;

    if (root->val < low)
    {
        return Traversal(root->right, low, high);
    }

    if (root->val > high)
    {
        return Traversal(root->left, low, high);
    }

    root->left = Traversal(root->left, low, high);
    root->right = Traversal(root->right, low, high);
    return root;
}

TreeNode *trimBSTv2(TreeNode *root, int low, int high)
{
    if (root == nullptr)
        return root;

    // 将root 移动到[low, high]区间内
    while (root != nullptr && (root->val < low || root->val > high))
    {
        if (root->val < low)
        {
            root = root->right;
        }
        else if (root->val > high)
        {
            root = root->left;
        }
    }

    // 此时root->val 在[low, high]之间
    TreeNode *cur = root;
    while (cur != nullptr)
    {
        // 更新cur的left，使其在为nullptr 或者 在[low, high]之间
        while (cur->left != nullptr && cur->left->val < low)
        {
            cur->left = cur->left->right;
        }

        // 指向cur->left，继续修剪
        cur = cur->left;
    }

    cur = root;

    while (cur != nullptr)
    {
        while (cur->right != nullptr && cur->right->val > high)
        {
            cur->right = cur->right->left;
        }

        cur = cur->right;
    }

    return root;
}