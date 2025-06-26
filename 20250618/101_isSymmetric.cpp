#include <alloca.h>
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

bool compare(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
        return true;
    if (left != nullptr && right == nullptr)
        return false;
    if (left == nullptr && right != nullptr)
        return false;

    if (left->val != right->val)
        return false;

    bool l_r = compare(left->left, right->right);
    bool r_r = compare(left->right, right->left);

    if (!(l_r && r_r))
        return false;

    return true;
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return compare(root->left, root->right);
}