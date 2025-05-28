#include <algorithm>
#include <unordered_map>
#include <vector>

// 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
// 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
// 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

//     node
//    /   \
//  left   right
//  / \    / \
// ll   lr rl   rr
// 其中 ll, lr, rl, rr 分别表示左子树的左节点、左子树的右节点、右子树的左节点和右子树的右节点。
// 小偷可以选择抢劫当前节点，或者不抢劫当前节点。

// 如果小偷抢劫了当前节点，那么他不能抢劫当前节点的子节点；
// 如果小偷没有抢劫当前节点，那么他可以选择抢劫当前节点的子节点。

// 根据子结点的状态，来决定当前节点的状态。
// 因此采用后序遍历的方式来解决这个问题。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> Traversalv3(TreeNode *node)
{
    if (node == nullptr)
    {
        return {0, 0}; // 返回 {不抢当前节点的最大值, 抢当前节点的最大值}
    }

    auto left = Traversalv3(node->left);
    auto right = Traversalv3(node->right);

    int rob_cur_node = node->val + left[0] + right[0]; // 抢当前节点，不能抢左子树和右子树
    int not_rob_cur_node = std::max(left[0], left[1]) +
                           std::max(right[0], right[1]); // 不抢当前节点，可以抢左子树和右子树
    return {not_rob_cur_node, rob_cur_node}; // 返回 {不抢当前节点的最大值, 抢当前节点的最大值}
}

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