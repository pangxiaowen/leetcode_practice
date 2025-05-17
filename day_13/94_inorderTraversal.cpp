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

    TreeNode *cur = root;

    while (cur != nullptr || !st.empty())
    {
        if (cur != nullptr) // 指针访问节点, 访问到最低层
        {
            st.push(cur);    // 将访问的节点放入栈中
            cur = cur->left; // 向左
        }
        else
        {
            cur = st.top(); // 到达底层, 弹出数据
            st.pop();
            res.push_back(cur->val); // 中
            cur = cur->right;        // 右
        }
    }

    return res;
}