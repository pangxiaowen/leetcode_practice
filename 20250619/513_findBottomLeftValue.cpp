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

// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
// 假设二叉树中至少有一个节点。

int findBottomLeftValue(TreeNode *root)
{
    std::queue<TreeNode *> que;
    que.push(root);

    TreeNode *left_node;
    while (!que.empty())
    {
        int size = que.size();
        left_node = que.front();

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();

            if (node->left != nullptr)
                que.push(node->left);
            if (node->right != nullptr)
                que.push(node->right);
        }
    }

    return left_node->val;
}

int max_depth = 0;
int left_value = 0;
void Traversal(TreeNode *node, int depth)
{
    if (node == nullptr)
        return;

    Traversal(node->left, depth + 1);
    Traversal(node->right, depth + 1);

    if (depth > max_depth)
    {
        max_depth = depth;
        left_value = node->val;
    }
}

int findBottomLeftValuev2(TreeNode *root)
{
    Traversal(root, 0);
    return left_value;
}