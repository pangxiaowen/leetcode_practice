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

bool has_path = false;
void Traversal(TreeNode *node, int targetSum)
{
    if (node->left == nullptr && node->right == nullptr && targetSum == node->val)
    {
        has_path = true;
        return;
    }

    if (node->left != nullptr)
        Traversal(node->left, targetSum - node->val);
    if (node->right != nullptr)
        Traversal(node->right, targetSum - node->val);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;
    Traversal(root, targetSum);
    return has_path;
}

bool hasPathSumv2(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;

    std::stack<TreeNode *> st;
    std::stack<int> offset;

    st.push(root);
    offset.push(targetSum - root->val);

    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();
        int value = offset.top();
        offset.pop();

        if (cur->left == nullptr && cur->right == nullptr && value == 0)
        {
            return true;
        }

        if (cur->left != nullptr)
        {
            st.push(cur->left);
            offset.push(value - cur->left->val);
        }

        if (cur->right != nullptr)
        {
            st.push(cur->right);
            offset.push(value - cur->right->val);
        }
    }

    return false;
}