#include <algorithm>
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

int pre = INT32_MIN;
bool is_valid_bst(TreeNode *root)
{
    if (root == nullptr)
        return true;

    if (!is_valid_bst(root->left))
        return false;

    if (root->val <= pre)
        return false;

    pre = root->val;

    return is_valid_bst(root->right);
}

bool is_valid_bst_v2(TreeNode *root)
{
    if (root == nullptr)
        return true;

    std::stack<TreeNode *> st;
    st.push(root);

    TreeNode *pre = nullptr;

    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();

        if (cur != nullptr)
        {
            if (cur->right != nullptr)
                st.push(cur->right);

            st.push(cur);
            st.push(nullptr);

            if (cur->left != nullptr)
                st.push(cur->left);
        }
        else
        {
            cur = st.top();
            st.pop();

            if (pre == nullptr)
            {
                pre = cur;
                continue;
            }

            if (cur->val <= pre->val)
            {
                return false;
            }
            pre = cur;
        }
    }

    return true;
}