#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 参数&返回值
bool compare(TreeNode *left, TreeNode *right)
{
    // 终止条件
    if (left == nullptr && right != nullptr)
    {
        return false;
    }
    else if (left != nullptr && right == nullptr)
    {
        return false;
    }
    else if (left == nullptr && right == nullptr)
    {
        return true;
    }
    else if (left->val != right->val) // 左右不为空，数值不同
    {
        return false;
    }

    // 左右不为空，数值相同，则继续向下进行
    bool lres = compare(left->left, right->right);
    bool rres = compare(left->right, right->left);
    return lres && rres;
}

bool compare_tree(TreeNode *root)
{
    if (root == nullptr)
        return true;

    return compare(root->left, root->right);
}

bool compare_tree_v2(TreeNode *root)
{
    if (root == nullptr)
        return true;

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    std::queue<TreeNode *> que;
    que.push(left);
    que.push(right);

    while (!que.empty())
    {
        left = que.front();
        que.pop();
        right = que.front();
        que.pop();

        // 终止条件
        if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left == nullptr && right == nullptr)
        {
            continue;
        }
        else if (left->val != right->val) // 左右不为空，数值不同
        {
            return false;
        }

        que.push(left->left);
        que.push(right->right);
        que.push(left->right);
        que.push(right->left);
    }
}

int main()
{
    TreeNode *root = new TreeNode();
    root->val = 0;

    TreeNode *left = new TreeNode();
    left->val = 1;

    TreeNode *right = new TreeNode();
    right->val = 2;

    root->left = left;
    root->right = right;

    compare_tree(root);

    std::cout << compare_tree(root) << std::endl;
    std::cout << std::endl;

    return 0;
}