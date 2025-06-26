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

void Traversal(TreeNode *node, std::vector<int> &vec)
{
    if (node == nullptr)
    {
        return;
    }

    Traversal(node->left, vec);
    vec.push_back(node->val);
    Traversal(node->right, vec);
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> result;
    Traversal(root, result);
    return result;
}

std::vector<int> inorderTraversalv2(TreeNode *root)
{
    std::vector<int> result;
    if (root == nullptr)
        return result;

    std::stack<TreeNode *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        auto cur_node = stack.top();
        stack.pop();

        if (cur_node != nullptr)
        {
            if (cur_node->right != nullptr)
                stack.push(cur_node->right);

            stack.push(cur_node);
            stack.push(nullptr);

            if (cur_node->left != nullptr)
                stack.push(cur_node->left);
        }
        else
        {
            auto node = stack.top();
            stack.pop();
            result.push_back(node->val);
        }
    }

    return result;
}