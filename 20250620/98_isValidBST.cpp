#include <algorithm>
#include <cstdint>
#include <list>
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

// 中序遍历是有序的
bool isValidBST(TreeNode *root)
{
    std::stack<TreeNode *> st;
    st.push(root);

    TreeNode *pre_node = nullptr;
    while (!st.empty())
    {
        TreeNode *cur_node = st.top();
        st.pop();

        if (cur_node != nullptr)
        {
            if (cur_node->right != nullptr)
                st.push(cur_node->right);

            st.push(cur_node);
            st.push(nullptr);

            if (cur_node->left != nullptr)
                st.push(cur_node->left);
        }
        else
        {
            cur_node = st.top();
            st.pop();

            if (pre_node != nullptr && cur_node->val <= pre_node->val)
            {
                return false;
            }

            pre_node = cur_node;
        }
    }

    return true;
}