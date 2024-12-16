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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return root;

    if (root->val == key)
    {
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;
        else
        {
            TreeNode *cur = root->right;
            while (cur->left != nullptr)
            {
                cur = cur->left;
            }

            cur->left = root->left;
            TreeNode *tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
    }

    if (root->val > key)
        root->left = deleteNode(root->left, key);
    if (root->val < key)
        root->right = deleteNode(root->right, key);

    return root;
}

TreeNode *deleteNode_v2(TreeNode *root, int key)
{
    if (root == nullptr)
        return root;

    if (root->val == key)
    {
        if (root->right == nullptr)
            return root->left;

        TreeNode *cur = root->right;
        while (cur->left != nullptr)
        {
            cur = cur->left;
        }
        std::swap(root->val, cur->val);
    }

    root->left = deleteNode_v2(root->left, key);
    root->right = deleteNode_v2(root->right, key);

    return root;
}