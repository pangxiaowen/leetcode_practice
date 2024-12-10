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

// 前序迭代法
std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    std::stack<TreeNode *> st;

    if (root == nullptr)
        return res;

    st.push(root);

    while (!st.empty())
    {
        auto node = st.top();
        res.push_back(node->val);
        st.pop();

        if (node->right != nullptr)
        {
            st.push(node->right);
        }

        if (node->left != nullptr)
        {
            st.push(node->left);
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

    auto res = preorderTraversal(root);

    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}