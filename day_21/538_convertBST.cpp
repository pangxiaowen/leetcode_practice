#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode() = default;
    TreeNode(int v) : val(v) {}
};

TreeNode *pre;
TreeNode *convertBST(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    convertBST(root->right);

    if (pre != nullptr)
        root->val += pre->val;
    pre = root;

    convertBST(root->left);

    return root;
}

TreeNode *convertBST_v2(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    std::stack<TreeNode *> st;
    st.push(root);

    TreeNode *pre;
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();

        if (cur != nullptr)
        {
            st.push(cur->left);
            st.push(cur);
            st.push(nullptr);
            st.push(cur->right);
        }
        else
        {
            cur = st.top();
            st.pop();

            if (pre != nullptr)
                cur->val = cur->val + pre->val;

            pre = cur;
        }
    }
}

TreeNode *pre_node = nullptr;
void Traversal(TreeNode *node)
{
    if (node == nullptr)
        return;

    Traversal(node->right);

    if (pre_node != nullptr)
    {
        node->val = node->val + pre_node->val;
    }
    pre_node = node;
    Traversal(node->left);
}