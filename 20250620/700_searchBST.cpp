#include <algorithm>
#include <list>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *Traversal(TreeNode *node, int val)
{
    if (node == nullptr)
        return nullptr;

    if (node->val == val)
    {
        return node;
    }

    if (node->val > val)
    {
        return Traversal(node->left, val);
    }

    if (node->val < val)
    {
        return Traversal(node->right, val);
    }

    return nullptr;
}

TreeNode *searchBST(TreeNode *root, int val) { return Traversal(root, val); }

TreeNode *searchBSTV2(TreeNode *root, int val)
{
    while (root != nullptr)
    {
        if (root->val == val)
        {
            break;
        }

        if (root->val > val)
            root = root->left;
        else if (root->val < val)
            root = root->right;
    }

    return root;
}