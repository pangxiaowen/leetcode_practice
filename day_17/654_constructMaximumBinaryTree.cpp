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

TreeNode *traversal(std::vector<int> &&vec)
{
    if (vec.empty())
        return nullptr;

    int index = 0;
    int max = INT_MIN;
    // 记录最大值以及索引
    for (int i = 0; i < vec.size(); ++i)
    {
        if (max < vec[i])
        {
            max = vec[i];
            index = i;
        }
    }

    TreeNode *root = new TreeNode();
    root->val = max;

    if (vec.size() == 1)
        return root;

    root->left = traversal({vec.begin(), vec.begin() + index});
    root->right = traversal({vec.begin() + index + 1, vec.end()});

    return root;
}

int main()
{

    std::vector<int> order{3, 2, 1, 6, 0, 5};

    auto root = traversal(std::move(order));

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