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

void Traversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::swap(node->left, node->right);
    Traversal(node->left);
    Traversal(node->right);
}

TreeNode *invertTree(TreeNode *root)
{
    Traversal(root);
    return root;
}

TreeNode *invertTreev2(TreeNode *root)
{
    if (root == nullptr)
        return root;

    std::stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        if (cur == nullptr)
            continue;

        std::swap(cur->left, cur->right);
        st.push(cur->left);
        st.push(cur->right);
    }

    return root;
}