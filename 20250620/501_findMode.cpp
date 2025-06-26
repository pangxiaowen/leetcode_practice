#include <algorithm>
#include <cstdint>
#include <list>
#include <math.h>
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

std::vector<int> result;
int count = 0;
int max_count = INT32_MIN;
TreeNode *pre_node = nullptr;

void Traversal(TreeNode *node)
{
    if (node == nullptr)
        return;

    Traversal(node->left);

    if (pre_node != nullptr)
    {
        if (pre_node->val == node->val)
        {
            count++;
        }
        else
        {
            count = 1;
        }
    }

    if (count > max_count)
    {
        max_count = count;
        result.clear();
        result.push_back(node->val);
    }
    else if (count == max_count)
    {
        result.push_back(node->val);
    }

    pre_node = node;

    Traversal(node->right);
}

std::vector<int> findMode(TreeNode *root)
{
    Traversal(root);
    return result;
}