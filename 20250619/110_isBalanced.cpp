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

bool is_balance = true;
int is_blanced(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int l_d = is_blanced(node->left);
    int r_d = is_blanced(node->right);

    if (std::abs(l_d - r_d) > 1 && is_balance)
    {
        is_balance = false;
    }

    return std::max(l_d, r_d) + 1;
}

bool isBalanced(TreeNode *root)
{
    is_blanced(root);
    return is_balance;
}