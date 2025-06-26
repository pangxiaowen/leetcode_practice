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

TreeNode *Traversal(TreeNode *node_1, TreeNode *node_2)
{
    if (node_1 == nullptr && node_2 == nullptr)
        return nullptr;

    if (node_1 == nullptr && node_2 != nullptr)
    {
        return node_2;
    }

    if (node_1 != nullptr && node_2 == nullptr)
    {
        return node_1;
    }

    TreeNode *node = new TreeNode();
    node->val = node_1->val + node_2->val;

    node->left = Traversal(node_1->left, node_2->left);
    node->right = Traversal(node_1->right, node_2->right);

    return node;
}

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) { return Traversal(root1, root2); }