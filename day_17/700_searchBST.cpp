#include <algorithm>
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

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;

    std::queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        TreeNode *cur = que.front();
        que.pop();

        if (cur->val == val)
            return cur;

        if (cur->left != nullptr)
        {
            que.push(cur->left);
        }

        if (cur->right != nullptr)
        {
            que.push(cur->right);
        }
    }

    return nullptr;
}

TreeNode *searchBST_V2(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;

    std::queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        TreeNode *cur = que.front();
        que.pop();

        if (cur->val == val)
            return cur;

        if (cur->val < val && cur->left != nullptr)
        {
            que.push(cur->left);
        }
        else if (cur->val > val && cur->right != nullptr)
        {
            que.push(cur->right);
        }
        else
        {
            return nullptr;
        }
    }

    return nullptr;
}

TreeNode *searchBST_V3(TreeNode *root, int val)
{
    while (root != nullptr)
    {
        if (root->val > val)
        {
            root = root->left;
        }
        else if (root->val < val)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }

    return nullptr;
}

TreeNode *res = nullptr;
void traversal(TreeNode *root, int val)
{
    if (root == nullptr)
        return;

    if (root->val == val)
    {
        res = root;
    }

    traversal(root->left, val);
    traversal(root->right, val);
}

TreeNode *traversal_v2(TreeNode *root, int val)
{
    if (root == nullptr || root->val == val)
        return root;

    TreeNode *result = nullptr;
    if (root->val > val)
        result = traversal_v2(root->left, val);

    if (root->val < val)
        result = traversal_v2(root->right, val);

    return nullptr;
}