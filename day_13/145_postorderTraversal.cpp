#include <algorithm>
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

// 后序迭代法 --> 左右中
// 前序--> 中左右
// 先进行 中右左 然后反转即可
std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    std::stack<TreeNode *> st;

    if (root == nullptr)
        return res;

    st.push(root);

    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        res.push_back(node->val);

        if (node->left != nullptr)
        {
            st.push(node->left);
        }

        if (node->right != nullptr)
        {
            st.push(node->right);
        }
    }

    std::reverse(res.begin(), res.end());

    return res;
}