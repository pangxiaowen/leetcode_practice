#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class TreeNode
{
  public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

TreeNode *traversal(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;

    if (root1 == nullptr && root2 != nullptr)
        return root2;

    if (root1 != nullptr && root2 == nullptr)
        return root1;

    TreeNode *root = new TreeNode();
    root->val = root1->val + root2->val;

    root->left = traversal(root1->left, root2->left);
    root->right = traversal(root1->right, root2->right);

    return root;
}

TreeNode *mergeTree(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr)
        return t2;
    if (t2 == nullptr)
        return t1;

    std::queue<TreeNode *> que;
    que.push(t1);
    que.push(t2);

    while (!que.empty())
    {
        TreeNode *node_1 = que.front();
        que.pop();
        TreeNode *node_2 = que.front();

        node_1->val = node_1->val + node_2->val;

        if (node_1->left != nullptr && node_2->left != nullptr)
        {
            que.push(node_1->left);
            que.push(node_2->left);
        }

        if (node_1->right != nullptr && node_2->right != nullptr)
        {
            que.push(node_1->right);
            que.push(node_2->right);
        }

        if (node_1->left == nullptr && node_2->left != nullptr)
            node_1->left = node_2->left;

        if (node_1->left == nullptr && node_2->left != nullptr)
            node_1->right = node_2->right;
    }

    return t1;
}
