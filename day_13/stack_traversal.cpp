#include <iostream>
#include <stack>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    std::stack<TreeNode *> st;

    if (root == nullptr)
        return res;

    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != nullptr)
        {
            st.pop();
            if (node->right != nullptr) // 空节点不入栈
                st.push(node->right);   // 添加右节点

            st.push(node);    // 添加中节点
            st.push(nullptr); // 中节点访问过,但是还没有处理, 加入空节点进行标记

            if (node->left != nullptr) // 空节点不入栈
                st.push(node->left);   // 添加左节点
        }
        else // 只有遇到空节点, 才会将下一个节点放进结果集
        {
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node->val);
        }
    }

    return res;
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    std::stack<TreeNode *> st;
    if (root != nullptr)
        st.push(root);

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        if (cur != nullptr)
        {
            // 前序 中左右
            if (cur->right != nullptr)
                st.push(cur->right);
            if (cur->left != nullptr)
                st.push(cur->left);

            st.push(cur);
            st.push(nullptr);
        }
        else
        {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
        }
    }

    return res;
}

std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    std::stack<TreeNode *> st;
    if (root != nullptr)
        st.push(root);

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        if (cur != nullptr)
        {
            // 后序--> 左右中
            st.push(cur);
            st.push(nullptr);

            if (cur->right != nullptr)
                st.push(cur->right);
            if (cur->left != nullptr)
                st.push(cur->left);
        }
        else
        {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
        }
    }

    return res;
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

    auto res = postorderTraversal(root);

    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}