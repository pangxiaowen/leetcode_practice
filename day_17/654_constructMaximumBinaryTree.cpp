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

TreeNode *traversal(std::vector<int> &&vec)
{
    if (vec.empty())
        return nullptr;

    int index = 0;
    int max = INT32_MIN;
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

TreeNode *Traversal(std::vector<int> &&vec)
{
    if (vec.size() == 0)
    {
        return nullptr;
    }

    // 找到最大值，以及index
    int max = INT32_MIN;
    int index = -1;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (max < vec[i])
        {
            max = vec[i];
            index = i;
        }
    }

    TreeNode *node = new TreeNode();
    node->val = max;

    if (vec.size() == 1)
        return node;

    node->left = Traversal({vec.begin(), vec.begin() + index - 1});
    node->right = Traversal({vec.begin() + index + 1, vec.end()});

    return node;
}

TreeNode *Traversalv2(std::vector<int> &vec, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode();
    if (right - left == 0)
    {
        node->val = vec[right];
        return node;
    }

    // 找到最大值，以及index
    int max = INT32_MIN;
    int index = -1;
    for (size_t i = left; i < right; ++i)
    {
        if (max < vec[i])
        {
            max = vec[i];
            index = i;
        }
    }
    node->val = max;

    if (left < index - 1)
        node->left = Traversalv2(vec, left, index - 1);

    if (right > index + 1)
        node->right = Traversalv2(vec, index + 1, right);

    return node;
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