#include <algorithm>
#include <cstdint>
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

TreeNode *Traversal(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return root;

    if (root->val >= p->val && root->val >= q->val)
    {
        TreeNode *l_p = Traversal(root->left, p, q);
        return l_p;
    }
    else if (root->val <= p->val && root->val <= q->val)
    {
        TreeNode *r_p = Traversal(root->right, p, q);
        return r_p;
    }
    else
    {
        return root;
    }

    return nullptr;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return Traversal(root, p, q);
}