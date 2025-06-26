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

    vec.push_back(node->val);
    Traversal(node->left, vec);
    Traversal(node->right, vec);
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> result;
    Traversal(root, result);
    return result;
}

std::vector<int> preorderTraversalv2(TreeNode *root)
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

        result.push_back(node->val);

        if (node->right != nullptr)
            stack.push(node->right);

        if (node->left != nullptr)
            stack.push(node->left);
    }

    return result;
}