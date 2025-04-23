#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

int sum_of_left_leaves(TreeNode *root)
{
    int sum = 0;
    std::queue<TreeNode *> queue;
    if (root != nullptr)
        queue.push(root);

    while (!queue.empty())
    {
        TreeNode *cur = queue.front();
        queue.pop();

        if (cur->left != nullptr)
        {
            if (cur->left->left == nullptr && cur->left->right == nullptr)
            {
                sum = sum + cur->val;
            }

            queue.push(cur->left);
        }

        if (cur->right != nullptr)
        {
            queue.push(cur->right);
        }
    }

    return sum;
}

void Traversal(TreeNode *node, int &res)
{
    if (node != nullptr)
        return;

    // TODO 判断是否存在左子叶
    if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr)
    {
        res += node->left->val;
    }

    Traversal(node->left, res);
    Traversal(node->right, res);
}

int sum_of_left_leaves_v2(TreeNode *root) {}