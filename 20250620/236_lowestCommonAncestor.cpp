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

TreeNode *Traversal(TreeNode *node, TreeNode *p, TreeNode *q)
{
    if (node == nullptr || node == p || node == q)
        return node;

    auto l_p = Traversal(node->left, p, q);
    auto r_p = Traversal(node->right, p, q);

    if (l_p != nullptr && r_p != nullptr)
    {
        return node;
    }

    if (l_p != nullptr)
    {
        return l_p;
    }

    if (r_p != nullptr)
    {
        return r_p;
    }

    return nullptr;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return Traversal(root, p, q);
}
