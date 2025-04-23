#include <iostream>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

//  1. 确认递归的参数以及返回值
void traversal(TreeNode *node, std::vector<int> &vec)
{
    // 2. 确认终止条件
    if (node == nullptr)
        return;

    // 3. 确认单层递归的逻辑

    // 前序遍历
    vec.push_back(node->val);
    traversal(node->left, vec);
    traversal(node->right, vec);

    // // 中序遍历
    // traversal(node->left, vec);
    // vec.push_back(node->val);
    // traversal(node->right, vec);

    // // 后序遍历
    // traversal(node->left, vec);
    // traversal(node->right, vec);
    // vec.push_back(node->val);
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> result;
    traversal(root, result);
    return result;
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

    auto res = preorderTraversal(root);

    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}
