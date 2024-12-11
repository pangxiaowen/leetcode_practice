#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

int depth(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int l_d = depth(node->left);
    int r_d = depth(node->right);

    int d = std::max(l_d, r_d) + 1;
    return d;
}

int depth_tree(TreeNode *root)
{
    depth(root);
}

int depth_v2(TreeNode *root)
{
    int depth = 0;
    std::queue<TreeNode *> que;
    if (root != nullptr)
        que.push(root);

    if (!que.empty())
    {
        int size = que.size();
        depth++;

        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = que.front();
            que.pop();

            if (cur->left != nullptr)
                que.push(cur->left);
            if (cur->right != nullptr)
                que.push(cur->right);
        }
    }

    return depth;
}