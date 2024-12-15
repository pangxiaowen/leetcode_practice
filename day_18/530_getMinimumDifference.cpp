#include <algorithm>
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

// 中序遍历 二叉搜索树 得到的结果是有序的
int min = INT32_MAX;
TreeNode *pre = nullptr;
void traversal(TreeNode *node)
{
    if (node == nullptr)
        return;

    traversal(node->left);

    if (pre != nullptr)
    {
        int dist = std::abs(node->val - pre->val);
        min = dist < min ? dist : min;
        pre = node;
    }
    pre = node;
    traversal(node->right);
}

int getMinimumDifference(TreeNode *root)
{
    int min = 0;
    if (root == nullptr)
        return min;

    TreeNode *pre = nullptr;
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

            st.push(cur);
            st.push(nullptr);

            if (cur->left != nullptr)
                st.push(cur->left);
        }
        else
        {
            cur = st.top();
            st.pop();

            if (pre != nullptr)
            {
                min = std::min(min, std::abs(pre->val - cur->val));
            }

            pre = cur;
        }
    }

    return min;
}