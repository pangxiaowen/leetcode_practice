#include <iostream>
#include <stack>
#include <vector>

class TreeNode
{
  public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

void Traversal(TreeNode *node, std::vector<int> &path, std::vector<std::string> &result)
{
    path.push_back(node->val);

    if (node->left == nullptr && node->right == nullptr)
    {
        std::string s_path;
        s_path.empty();
        for (int i = 0; i < path.size() - 1; i++)
        {
            s_path += std::to_string(path[i]);
            s_path += "->";
        }

        s_path += std::to_string(path[path.size() - 1]);
        result.push_back(s_path);
        return;
    }

    if (node->left)
    {
        Traversal(node->left, path, result);
        path.pop_back();
    }

    if (node->right)
    {
        Traversal(node->left, path, result);
        path.pop_back();
    }
}