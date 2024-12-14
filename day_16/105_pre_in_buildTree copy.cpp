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

TreeNode *traversal(std::vector<int> &&preorder, std::vector<int> &&inorder)
{
    if (preorder.empty())
        return nullptr;

    TreeNode *root = new TreeNode();
    root->val = preorder[0];

    if (preorder.size() == 1)
        return root;

    int index = 0;
    for (size_t i = 0; i < inorder.size(); ++i)
    {
        if (inorder[i] == root->val)
        {
            index = i;
            break;
        }
    }

    root->left = traversal({preorder.begin() + 1, preorder.begin() + index + 1},
                           {inorder.begin(), inorder.begin() + index - 1 + 1}); // 前序和中序的长度是一样的,  左闭右开
    root->right =
        traversal({preorder.begin() + index + 1, preorder.end()}, {inorder.begin() + index + 1, inorder.end()});

    return root;
}

int main()
{

    std::vector<int> preorder{3, 9, 20, 15, 7};
    std::vector<int> inorder{9, 3, 15, 20, 7};

    auto root = traversal(std::move(preorder), std::move(inorder));

    std::stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();

        std::cout << cur->val << std::endl;

        if (cur->right != nullptr)
            st.push(cur->right);
        if (cur->left != nullptr)
            st.push(cur->left);
    }

    return 0;
}