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

// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
// 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

// 1. 先找到这个节点
// 2. 删除它

// 如何删除它
// 1. 如果左右子树木都为nullptr， 即该节点是叶子节点，直接置为nullptr即可。
// 2. 如果仅左子树存在或者右子树存在，直接使用左/右孩代替该节点即可
// 3. 如果左右子树木都存在，则取右子树的最小值代替当前值。

TreeNode *Traversal(TreeNode *node, int key)
{
    if (node == nullptr)
        return node;

    if (node->val == key)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        if (node->left != nullptr && node->right == nullptr)
        {
            TreeNode *cur = node->left;
            delete node;
            return cur;
        }

        if (node->left == nullptr && node->right != nullptr)
        {
            TreeNode *cur = node->right;
            delete node;
            return cur;
        }

        if (node->left != nullptr && node->right != nullptr)
        {
            TreeNode *cur = node->right;
            while (cur->left != nullptr)
            {
                cur = cur->left;
            }

            // 此时ptr的子树木只有两种状态，
            // 左->nullptr 右->nullptr
            // 左->nullptr 右->!nullptr
            // 把key的左子树，插入到cur的左子树木，即可
            cur->left = node->left;
            delete node;
            return node->right;
        }
    }

    node->left = Traversal(node->left, key);
    node->right = Traversal(node->right, key);
    return node;
}

// 普通二叉树的删除节点
TreeNode *Traversalv2(TreeNode *node, int key)
{
    if (node == nullptr)
        return node;

    if (node->val == key)
    {
        if (node->right == nullptr)
        {
            return node->left;
        }

        TreeNode *cur = node->right;
        while (cur->left != nullptr)
        {
            cur = cur->left;
        }

        std::swap(cur->val, node->val);
    }

    node->left = Traversal(node->left, key);
    node->right = Traversal(node->right, key);
    return node;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    Traversal(root, key);
    return root;
}