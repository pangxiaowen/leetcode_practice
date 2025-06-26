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

int count = 0;
void cal_count(TreeNode *node)
{
    if (node == nullptr)
        return;

    count++;
    cal_count(node->left);
    cal_count(node->right);
}

int cal_count_v2(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int l_c = cal_count_v2(node->left);
    int r_c = cal_count_v2(node->right);

    int cur_c = l_c + r_c + 1;
    return cur_c;
}

int cal_count_v3(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    // 根据完全二叉树的性质判断， 判断当前树是否为完全二叉树
    TreeNode *left = node->left;
    TreeNode *right = node->right;
    int left_depth = 0;
    int right_depth = 0;

    while (left != nullptr)
    {
        left = left->left;
        left_depth++;
    }

    while (right != nullptr)
    {
        right = right->right;
        right_depth++;
    }

    // 当前树是完全二叉树
    if (left_depth == right_depth)
    {
        return (2 << left_depth) - 1;
    }

    return 1 + cal_count_v3(node->left) + cal_count_v3(node->right);
}

int countNodes(TreeNode *root)
{
    cal_count(root);
    return count;
}
