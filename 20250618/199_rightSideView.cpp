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

std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<int> result;
    if (root == nullptr)
        return result;

    std::queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            auto cur = que.front();
            que.pop();

            if (cur->left != nullptr)
                que.push(cur->left);
            if (cur->right != nullptr)
                que.push(cur->right);

            if (i == size - 1)
            {
                result.push_back(cur->val);
            }
        }
    }
    return result;
}