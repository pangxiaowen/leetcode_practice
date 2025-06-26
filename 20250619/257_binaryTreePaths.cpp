
#include <math.h>
#include <queue>
#include <stack>
#include <string>
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

std::vector<std::string> result;
void Traversal(TreeNode *node, std::string str)
{
    str = str + "->" + std::to_string(node->val);
    if (node->left == nullptr && node->right == nullptr)
    {
        result.push_back(str);
        return;
    }

    if (node->left != nullptr)
        Traversal(node->left, str);
    if (node->right != nullptr)
        Traversal(node->right, str);
}

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    if (root == nullptr)
        return result;

    std::string str = std::to_string(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        result.push_back(str);
    }

    if (root->left != nullptr)
        Traversal(root->left, str);
    if (root->right != nullptr)
        Traversal(root->right, str);
    return result;
}

void Traversalv2(TreeNode *node, std::string str)
{
    str += std::to_string(node->val);
    if (node->left == nullptr && node->right == nullptr)
    {
        result.push_back(str);
        return;
    }

    if (node->left != nullptr)
        Traversalv2(node->left, str + "->");
    if (node->right != nullptr)
        Traversalv2(node->right, str + "->");
}

std::vector<std::string> binaryTreePathsv2(TreeNode *root)
{
    if (root == nullptr)
        return result;

    std::string str;
    Traversalv2(root, str);
    return result;
}