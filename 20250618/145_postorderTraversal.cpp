#include <stack>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 **/

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
    Traversal(node->right, vec);
    vec.push_back(node->val);
}

std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> result;
    Traversal(root, result);
    return result;
}

std::vector<int> postorderTraversalv2(TreeNode *root)
{
    std::vector<int> result;

    if (root == nullptr)
        return result;

    std::stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        auto node = stack.top();
        stack.pop();

        if (node != nullptr)
        {
            stack.push(node);
            stack.push(nullptr);

            if (node->right != nullptr)
                stack.push(node->right);

            if (node->left != nullptr)
                stack.push(node->left);
        }
        else
        {
            auto cur_node = stack.top();
            stack.pop();
            result.push_back(cur_node->val);
        }
    }

    return result;
}