#include <algorithm>
#include <unordered_map>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::unordered_map<TreeNode *, int> g_cache;

int Traversal(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    if (node->left == nullptr && node->right == nullptr)
        return node->val;

    if (g_cache.find(node) != g_cache.end())
        return g_cache[node];

    // 抢当前节点
    int val_1 = node->val;
    if (node->left != nullptr)
        val_1 += Traversal(node->left->left) + Traversal(node->left->right);
    if (node->right != nullptr)
        val_1 += Traversal(node->right->left) + Traversal(node->right->right);

    // 不抢当前节点
    int val_2 = Traversal(node->left) + Traversal(node->right);

    g_cache[node] = std::max(val_1, val_2);
    return g_cache[node];
}

std::vector<int> Traversalv2(TreeNode *node)
{
    if (node == nullptr)
        return {0, 0};

    auto val_left = Traversalv2(node->left);
    auto val_right = Traversalv2(node->right);

    int val_1 = node->val + val_left[0] + val_right[0]; //偷当前节点， 不能偷left 和 right
    int val_2 =
        std::max(val_left[0], val_left[1]) + std::max(val_right[0], val_right[1]); // 不偷当前节点

    return {val_2, val_1};
}

int rob(TreeNode *root)
{
    auto res = Traversalv2(root);
    return std::max(res[0], res[1]);
}