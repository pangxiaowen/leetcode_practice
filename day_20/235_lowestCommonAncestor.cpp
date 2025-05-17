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
    if (root == p || root == q || root == nullptr)
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

TreeNode *lowest_common_ancestor_v3(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return root;

    if (root->val > p->val && root->val > q->val)
    {
        TreeNode *left = lowest_common_ancestor_v3(root, p, q);
        if (left != nullptr)
            return left;
    }
    if (root->val < p->val && root->val < q->val)
    {
        TreeNode *right = lowest_common_ancestor_v3(root, p, q);
        if (right != nullptr)
            return right;
    }

    return root;
}

TreeNode *lowest_common_ancestor_v4(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root != nullptr)
    {
        if (root->val > p->val && root->val > q->val)
            root = root->left;
        else if (root->val < p->val && root->val < q->val)
            root = root->right;
        else
            return root;
    }
}

TreeNode *Traversal(TreeNode *node, TreeNode *p, TreeNode *q)
{
    if (node == p || node == q || node == nullptr)
    {
        return node;
    }

    TreeNode *left_node = nullptr, *right_node = nullptr;
    if (node->val >= p->val || node->val >= q->val)
        left_node = Traversal(node->left, p, q);

    if (node->val <= p->val || node->val <= q->val)
        right_node = Traversal(node->right, p, q);

    if (left_node != nullptr && right_node != nullptr)
    {
        return node;
    }

    if (left_node != nullptr)
    {
        return left_node;
    }

    if (right_node != nullptr)
    {
        return right_node;
    }

    return nullptr;
}

TreeNode *Traversalv2(TreeNode *node, TreeNode *p, TreeNode *q)
{
    if (node == p || node == q || node == nullptr)
    {
        return node;
    }

    if (node->val > p->val && node->val > q->val)
    {
        return Traversal(node->left, p, q);
    }
    else if (node->val < p->val && node->val < q->val)
    {
        return Traversal(node->right, p, q);
    }
    else
    {
        return node;
    }
    return nullptr;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return Traversal(root, p, q);
}

TreeNode *lowestCommonAncestorv2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root != nullptr)
    {
        if (root->val > p->val && root->val > q->val)
        {
            root = root->left;
        }
        else if (root->val < p->val && root->val < q->val)
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