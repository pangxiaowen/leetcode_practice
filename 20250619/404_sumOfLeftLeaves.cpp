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

// 给定二叉树的根节点 root ，返回所有左叶子之和。

int sum = 0;
void Traversal(TreeNode *node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        return;
    }

    if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr)
    {
        sum += node->left->val;
    }

    if (node->left != nullptr)
    {
        Traversal(node->left);
    }
    if (node->right != nullptr)
    {
        Traversal(node->right);
    }
}

int sumOfLeftLeaves(TreeNode *root)
{
    Traversal(root);
    return sum;
}

int sumOfLeftLeavesv2(TreeNode *root)
{
    int result = 0;
    if (root == nullptr)
        return result;

    std::stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();

        if (cur != nullptr)
        {
            if (cur->right != nullptr)
                st.push(cur->right);

            if (cur->left != nullptr)
                st.push(cur->left);

            st.push(cur);
            st.push(nullptr);
        }
        else
        {
            TreeNode *node = st.top();
            st.pop();

            if (node->left != nullptr && node->left->left == nullptr &&
                node->left->right == nullptr)
            {
                result += node->left->val;
            }
        }
    }

    return result;
}