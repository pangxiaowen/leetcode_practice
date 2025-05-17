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
    TreeNode(int v) : val(v) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *node = new TreeNode();
    node->val = val;

    if (root == nullptr)
        return node;

    TreeNode *head = root;
    TreeNode *pre;
    while (root != nullptr)
    {
        pre = root;
        if (root->val < node->val)
        {
            root = root->right;
        }
        else if (root->val > node->val)
        {
            root = root->left;
        }
    }

    if (pre->val > node->val)
        pre->left = node;
    if (pre->val < node->val)
        pre->right = node;

    return head;
}

TreeNode *Travseral(TreeNode *root, int val)
{
    // 当遍历到叶子的时候，说明找到插入位置了
    if (root == nullptr)
        return new TreeNode(val);

    if (root->val > val)
    {
        root->left = Travseral(root->left, val);
    }

    if (root->val < val)
    {
        root->right = Travseral(root->right, val);
    }

    return root;
}
