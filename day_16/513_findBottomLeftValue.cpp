#include <cstdint>
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

int find_bottom_left_value(TreeNode *root)
{
    int val = 0;
    std::queue<TreeNode *> queue;
    if (root != nullptr)
        queue.push(root);

    while (!queue.empty())
    {
        int size = queue.size();
        val = queue.front()->val;

        for (int i = 0; i < size; --i)
        {
            TreeNode *cur = queue.front();
            queue.pop();

            if (cur->left != nullptr)
                queue.push(cur->left);

            if (cur->right != nullptr)
                queue.push(cur->right);
        }
    }

    return val;
}

int max_depth = INT32_MIN;
int result;
void traversal(TreeNode *root, int depth)
{
    // 终止条件
    if (root->left == nullptr && root->right == nullptr)
    {
        if (max_depth < depth)
        {
            max_depth = depth;
            result = root->val;
        }
        return;
    }

    if (root->left != nullptr)
    {
        depth++;
        traversal(root->left, depth);
        depth--;
    }

    if (root->right != nullptr)
    {
        depth++;
        traversal(root->right, depth);
        depth--;
    }

    return;
}