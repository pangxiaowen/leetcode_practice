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
};

TreeNode *lowest_common_ancestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == p || root == q || root == nullptr)
        return root;

    TreeNode *left = lowest_common_ancestor(root->left, p, q);
    TreeNode *right = lowest_common_ancestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }

    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
}

// 二叉搜索树的公共祖先， 第一个满足p < val < q 就是最近公共祖先。 采用中序遍历可以实现顺序访问。
TreeNode *lowest_common_ancestor_v2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return root;
    std::stack<TreeNode *> st;
    st.push(root);

    if (p->val > q->val)
        std::swap(p, q);

    while (!st.empty())
    {
        auto cur = st.top();
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
            cur = st.top();
            st.pop();

            if (cur->val >= p->val && cur->val <= q->val)
            {
                return cur;
            }
        }
    }

    return nullptr;
}

TreeNode *lowest_common_ancestor_v3(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return root;

    if (root->val > p->val && root->val > q->val)
    {
        TreeNode *left = lowest_common_ancestor_v3(root, p, q);
        if (left != nullptr)
            return left;
    }
    if (root->val < p->val && root->val < q->val)
    {
        TreeNode *right = lowest_common_ancestor_v3(root, p, q);
        if (right != nullptr)
            return right;
    }

    return root;
}

TreeNode *lowest_common_ancestor_v3(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root != nullptr)
    {
        if (root->val > p->val && root->val > q->val)
            root = root->left;
        else if (root->val < p->val && root->val < q->val)
            root = root->right;
        else
            return root;
    }
}