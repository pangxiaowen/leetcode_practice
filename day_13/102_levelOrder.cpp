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

std::vector<int> levelOrder(TreeNode *root)
{
    std::vector<int> res;
    std::queue<TreeNode *> que;
    if (root != nullptr)
        que.push(root);

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();
        res.push_back(cur->val);

        if (cur->left != nullptr)
            que.push(cur->left);
        if (cur->right != nullptr)
            que.push(cur->right);
    }

    return res;
}

std::vector<std::vector<int>> levelOrder_v2(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> que;
    if (root != nullptr)
        que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        std::vector<int> vec;
        for (size_t i = 0; i < size; ++i)
        {
            auto cur = que.front();
            que.pop();
            vec.push_back(cur->val);

            if (cur->left != nullptr)
                que.push(cur->left);
            if (cur->right != nullptr)
                que.push(cur->right);
        }

        res.push_back(vec);
    }
    return res;
}

// 参数以及返回值
void order(TreeNode *cur, std::vector<std::vector<int>> &res, int depth)
{
    // 终止条件
    if (cur == nullptr)
        return;

    if (res.size() == depth)
        res.push_back(std::vector<int>());

    res[depth].push_back(cur->val);
    order(cur->left, res, depth + 1);
    order(cur->right, res, depth + 1);
}

std::vector<std::vector<int>> levelOrder_v3(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    int depth = 0;
    order(root, res, depth);
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

    auto res = levelOrder_v2(root);

    for (auto it : res)
    {
        for (auto i : it)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}