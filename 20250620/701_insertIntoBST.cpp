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

TreeNode *Traversal(TreeNode *node, int val)
{
    if (node == nullptr)
    {
        TreeNode *in_node = new TreeNode();
        in_node->val = val;
        return node;
    }

    if (node->val > val)
    {
        node->left = Traversal(node->left, val);
    }

    if (node->val < val)
    {
        node->right = Traversal(node->right, val);
    }

    return node;
}

TreeNode *insertIntoBST(TreeNode *root, int val) { return Traversal(root, val); }