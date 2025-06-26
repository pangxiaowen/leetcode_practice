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

void levelTraversal(TreeNode *node, std::vector<std::vector<int>> &result, int depth)
{
    if (node == nullptr)
        return;

    if (result.size() == depth)
    {
        result.push_back(std::vector<int>());
    }

    result[depth].push_back(node->val);
    levelTraversal(node->left, result, depth + 1);
    levelTraversal(node->right, result, depth + 1);
}

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> result;
    if (root == nullptr)
        return result;

    std::queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {

        int size = que.size();
        std::vector<int> tmp;
        for (int i = 0; i < size; i++)
        {
            auto cur = que.front();
            que.pop();

            tmp.push_back(cur->val);

            if (cur->left != nullptr)
                que.push(cur->left);
            if (cur->right != nullptr)
                que.push(cur->right);
        }

        result.push_back(tmp);
    }
    return result;
}