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

bool traversal(TreeNode *node, int count)
{
    // 如果是叶子节点且count==0则说明找到了目标和
    if (node->left == nullptr && node->right == nullptr && count == 0)
        return true;
    // 遇到叶子节点, 但是count不等于0, 说明查找失败
    if (node->left == nullptr && node->right == nullptr)
        return false;

    if (node->left != nullptr)
    {
        if (traversal(node->left, count - node->left->val))
            return true;
    }

    if (node->left != nullptr)
    {
        if (traversal(node->right, count - node->right->val))
            return true;
    }
    return false;
}

bool hasPathSum(TreeNode *root, int count)
{
    if (root != nullptr)
    {
        return traversal(root, count - root->val);
    }
    return false;
}

bool hasPathSum_v2(TreeNode *root, int count)
{
    if (root == nullptr)
        return false;

    std::stack<std::pair<TreeNode *, int>> st;
    st.push({root, root->val});

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        if (cur.first->left == nullptr && cur.first->right == nullptr && count == cur.second)
            return true;

        if (cur.first->right != nullptr)
        {
            st.push({cur.first->right, cur.second + cur.first->right->val});
        }

        if (cur.first->left != nullptr)
        {
            st.push({cur.first->left, cur.second + cur.first->left->val});
        }
    }

    return false;
}
