#include <iostream>
#include <stack>
#include <string>
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

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    std::stack<TreeNode *> st_node;
    std::stack<std::string> st_path;
    std::vector<std::string> result;

    if (root == nullptr)
        return result;

    st_node.push(root);
    st_path.push("");

    while (!st_node.empty())
    {
        TreeNode *cur = st_node.top();
        st_node.pop();

        std::string path = st_path.top();
        st_path.pop();
        path += std::to_string(cur->val);

        if (cur->left == nullptr && cur->right == nullptr)
        {
            result.push_back(path);
            continue;
        }

        if (cur->left != nullptr)
        {
            st_node.push(cur->left);
            st_path.push(path + "->");
        }

        if (cur->right != nullptr)
        {
            st_node.push(cur->right);
            st_path.push(path + "->");
        }
    }

    return result;
}