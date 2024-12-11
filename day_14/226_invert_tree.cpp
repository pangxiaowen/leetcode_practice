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

void invert(TreeNode *node)
{
    if (node == nullptr)
        return;

    std::swap(node->left, node->right);
    invert(node->left);
    invert(node->right);
}

void invert_tree(TreeNode *root)
{
    invert(root);
}

void invert_tree_v2(TreeNode *root)
{
    std::stack<TreeNode *> st;
    if (root != nullptr)
        st.push(root);

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        std::swap(cur->left, cur->right);

        if (cur->right != nullptr)
        {
            st.push(cur->right);
        }

        if (cur->left != nullptr)
        {
            st.push(cur->left);
        }
    }
}

void invert_tree_v3(TreeNode *root)
{
    std::stack<TreeNode *> st;
    if (root != nullptr)
        st.push(root);
    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        if (cur != nullptr)
        {
            if (cur->right != nullptr)
            {
                st.push(cur->right);
            }

            if (cur->left != nullptr)
            {
                st.push(cur->left);
            }

            st.push(cur);
            st.push(nullptr);
        }
        else
        {
            cur = st.top();
            st.pop();
            std::swap(cur->left, cur->right);
        }
    }
}

void invert_tree_v4(TreeNode *root)
{
    std::queue<TreeNode *> que;
    if (root != nullptr)
        que.push(root);

    while (!que.empty())
    {
        auto cur = que.front();
        std::swap(cur->left, cur->right);
        que.pop();

        if (cur->left != nullptr)
        {
            que.push(cur->left);
        }

        if (cur->right != nullptr)
        {
            que.push(cur->right);
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode();
    root->val = 0;

    TreeNode *left = new TreeNode();
    left->val = 1;

    TreeNode *right = new TreeNode();
    right->val = 2;

    root->left = left;
    root->right = right;

    invert_tree_v4(root);

    std::cout << root->val << std::endl;
    std::cout << root->left->val << std::endl;
    std::cout << root->right->val << std::endl;
    std::cout << std::endl;

    return 0;
}